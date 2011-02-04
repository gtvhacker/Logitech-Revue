/*
 * H.264 encoder
 * Copyright (c) 2006-2007 Expertisecentrum Digitale Media, UHasselt
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define MVTABLE_OFFSET    (128*4)

static const char mv_len_table[MVTABLE_OFFSET*2+1] =
{
    21,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,13,
    13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
    13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
    13,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
    11,11,9,9,9,9,9,9,9,9,7,7,7,7,5,
    5,3,1,3,5,5,7,7,7,7,9,9,9,9,9,
    9,9,9,11,11,11,11,11,11,11,11,11,11,11,11,
    11,11,11,11,13,13,13,13,13,13,13,13,13,13,13,
    13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
    13,13,13,13,13,13,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    15,15,15,15,15,15,15,15,15,15,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
    17,17,17,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,
    19,19,19,19,21
};

static const int sae_codeblocksize_relation[13][8] = {
{55,1590,1796,1865,1925,1977,2010,2021},
{27,1328,1525,1593,1649,1699,1729,1741},
{20,1097,1288,1353,1405,1449,1479,1485},
{17,878,1063,1130,1177,1217,1244,1250},
{16,667,875,945,992,1027,1051,1055},
{18,491,704,790,835,869,891,895},
{0,352,538,658,718,747,769,774},
{0,243,398,500,561,643,672,683},
{0,163,278,363,446,487,518,568},
{0,98,197,259,313,368,425,453},
{0,53,133,186,224,259,293,326},
{0,22,81,126,162,188,210,231},
{0,14,47,79,106,135,156,173}
};

