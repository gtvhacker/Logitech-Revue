#
# Makefile for the kernel block layer
#

obj-y	:= elevator.o ll_rw_blk.o ioctl.o genhd.o scsi_ioctl.o

obj-$(CONFIG_IOSCHED_NOOP)	+= noop-iosched.o
obj-$(CONFIG_IOSCHED_AS)	+= as-iosched.o
obj-$(CONFIG_IOSCHED_DEADLINE)	+= deadline-iosched.o
obj-$(CONFIG_IOSCHED_CFQ)	+= cfq-iosched.o

obj-$(CONFIG_BLK_DEV_IO_TRACE)	+= blktrace.o
obj-$(CONFIG_SBULL)	+= sbull/
