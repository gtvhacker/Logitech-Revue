/*
 *  drivers/switch/switch_class.c
 *
 * Copyright (C) 2008 Google, Inc.
 * Author: Mike Lockwood <lockwood@android.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
*/

#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/switch.h>

struct class *switch_class = NULL;
static atomic_t device_count;

static ssize_t state_show(struct class_device *cdev, char *buf)
{
	struct switch_dev *sdev = (struct switch_dev *)
		class_get_devdata(cdev);

	if (sdev->print_state) {
		int ret = sdev->print_state(sdev, buf);
		if (ret >= 0)
			return ret;
	}
	return sprintf(buf, "%d\n", sdev->state);
}

static ssize_t name_show(struct class_device *cdev, char *buf)
{
	struct switch_dev *sdev = (struct switch_dev *)
		class_get_devdata(cdev);

	if (sdev->print_name) {
		int ret = sdev->print_name(sdev, buf);
		if (ret >= 0)
			return ret;
	}
	return sprintf(buf, "%s\n", sdev->name);
}

static CLASS_DEVICE_ATTR(state, S_IRUGO | S_IWUSR, state_show, NULL);
static CLASS_DEVICE_ATTR(name, S_IRUGO | S_IWUSR, name_show, NULL);

void switch_set_state(struct switch_dev *sdev, int state)
{
	char name_buf[120];
	char state_buf[120];
	char *prop_buf;
	char *envp[3];
	int env_offset = 0;
	int length;

	if (sdev->state != state) {
		sdev->state = state;

		prop_buf = (char *)get_zeroed_page(GFP_KERNEL);
		if (prop_buf) {
			length = name_show(sdev->cdev, prop_buf);
			if (length > 0) {
				if (prop_buf[length - 1] == '\n')
				   prop_buf[length - 1] = 0;
				snprintf(name_buf, sizeof(name_buf), "SWITCH_NAME=%s", prop_buf);
				envp[env_offset++] = name_buf;
			}
			length = state_show(sdev->cdev, prop_buf);
			if (length > 0) {
				if (prop_buf[length - 1] == '\n')
				   prop_buf[length - 1] = 0;
				snprintf(state_buf, sizeof(state_buf), "SWITCH_STATE=%s", prop_buf);
				envp[env_offset++] = state_buf;
			}
			envp[env_offset] = NULL;
			kobject_uevent_env(&sdev->cdev->kobj, KOBJ_CHANGE, envp);
			free_page((unsigned long)prop_buf);
		}
		else {
			printk(KERN_ERR "out of memory in switch_set_state\n");
			kobject_uevent(&sdev->cdev->kobj, KOBJ_CHANGE);
		}
	}
}

static int create_switch_class(void)
{
	if (!switch_class) {
		switch_class = class_create(THIS_MODULE, "switch");
		if (IS_ERR(switch_class))
			return PTR_ERR(switch_class);
		atomic_set(&device_count, 0);
	}

	return 0;
}

int switch_dev_register(struct switch_dev *sdev)
{
	int ret;

	if (!switch_class) {
		ret = create_switch_class();
		if (ret < 0)
			return ret;
	}

	sdev->index = atomic_inc_return(&device_count);
	sdev->cdev = class_device_create(switch_class, NULL,
		MKDEV(0, sdev->index), NULL, sdev->name);
	if (IS_ERR(sdev->cdev))
		return PTR_ERR(sdev->cdev);

	ret = class_device_create_file(sdev->cdev, &class_device_attr_state);
	if (ret < 0)
		goto err_create_file_1;
	ret = class_device_create_file(sdev->cdev, &class_device_attr_name);
	if (ret < 0)
		goto err_create_file_2;

	class_set_devdata(sdev->cdev, sdev);
	sdev->state = 0;
	return 0;

err_create_file_2:
	class_device_remove_file(sdev->cdev, &class_device_attr_state);
err_create_file_1:
	class_device_destroy(switch_class, MKDEV(0, sdev->index));
	printk(KERN_ERR "switch: Failed to register driver %s\n", sdev->name);

	return ret;
}
EXPORT_SYMBOL_GPL(switch_dev_register);

void switch_dev_unregister(struct switch_dev *sdev)
{
	class_device_remove_file(sdev->cdev, &class_device_attr_name);
	class_device_remove_file(sdev->cdev, &class_device_attr_state);
	class_device_destroy(switch_class, MKDEV(0, sdev->index));
	class_set_devdata(sdev->cdev, NULL);
}
EXPORT_SYMBOL_GPL(switch_dev_unregister);

static int __init switch_class_init(void)
{
	return create_switch_class();
}

static void __exit switch_class_exit(void)
{
	class_destroy(switch_class);
}

module_init(switch_class_init);
module_exit(switch_class_exit);

MODULE_AUTHOR("Mike Lockwood <lockwood@android.com>");
MODULE_DESCRIPTION("Switch class driver");
MODULE_LICENSE("GPL");
