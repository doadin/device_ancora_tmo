/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_SENSORS_H
#define ANDROID_SENSORS_H

#include <stdint.h>
#include <errno.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <linux/input.h>

#include <hardware/hardware.h>
#include <hardware/sensors.h>

__BEGIN_DECLS

/*****************************************************************************/

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define ID_A (0)
#define ID_M (1)
#define ID_O (2)
#define ID_P (3)

/*****************************************************************************/

/*
 * The SENSORS Module
 */

/* the GP2A is a binary proximity sensor that triggers around 5 cm on
 * this hardware */
#define PROXIMITY_THRESHOLD_GP2A  5.0f

/*****************************************************************************/

/* For Accelerometer */
#define EVENT_TYPE_ACCEL_X          REL_X
#define EVENT_TYPE_ACCEL_Y          REL_Y
#define EVENT_TYPE_ACCEL_Z          REL_Z
//#define EVENT_TYPE_ACCEL_STATUS     ABS_RX

/* Fusion Orientaion */
#define EVENT_TYPE_YAW              REL_X
#define EVENT_TYPE_PITCH            REL_Y
#define EVENT_TYPE_ROLL             REL_Z
#define EVENT_TYPE_ORIENT_STATUS    ABS_WHEEL //8 

/* For Magnetometer */
#define EVENT_TYPE_MAGV_X           ABS_RY
#define EVENT_TYPE_MAGV_Y           ABS_RZ
#define EVENT_TYPE_MAGV_Z           ABS_THROTTLE
#define EVENT_TYPE_MAGV_STATUS      ABS_RUDDER

#define EVENT_TYPE_PROXIMITY        ABS_DISTANCE
#define EVENT_TYPE_LIGHT            ABS_MISC

// conversion of acceleration data to SI units (m/s^2)
#define RANGE_A                     (2*GRAVITY_EARTH)
#define RESOLUTION_A                (RANGE_A/(512))
#define CONVERT_A                   (1.0f/1000000.0f)
#define CONVERT_A_X                 (CONVERT_A)
#define CONVERT_A_Y                 (CONVERT_A)
#define CONVERT_A_Z                 (CONVERT_A)

// conversion of magnetic data to uT units
#define RANGE_M                     300.0f
#define RESOLUTION_M                (RANGE_M/(512))
#define CONVERT_M                   (1.0f/1000.0f)
#define CONVERT_M_X                 (CONVERT_M)
#define CONVERT_M_Y                 (CONVERT_M)
#define CONVERT_M_Z                 (CONVERT_M)

/* conversion of orientation data to degree units */
#define RANGE_O                     360.0f
#define RESOLUTION_O                (RANGE_O/(256))
#define CONVERT_O                   (1.0f/1000.0f)
#define CONVERT_O_A                 (CONVERT_O)
#define CONVERT_O_P                 (CONVERT_O)
#define CONVERT_O_R                 (CONVERT_O)

#define CONVERT_Q14					(1.0f / 16384.0f)
#define CONVERT_Q16					(1.0f / 65536.0f)
#define CONVERT_AKM_G				(GRAVITY_EARTH / 720.0f)

// factory ak8975
#define AK8975_DEFAULT_DELAY               (200 * 1000000)

#define AK8975_LSG                         (1000.0f)
#define AK8975_CONVERT_A                   (GRAVITY_EARTH / AK8975_LSG)
#define AK8975_CONVERT_A_X                 (-AK8975_CONVERT_A)
#define AK8975_CONVERT_A_Y                 (AK8975_CONVERT_A)
#define AK8975_CONVERT_A_Z                 (-AK8975_CONVERT_A)

#define AK8975_CONVERT_M                   (1.0f/16.0f)
#define AK8975_CONVERT_M_X                 (AK8975_CONVERT_M)
#define AK8975_CONVERT_M_Y                 (-AK8975_CONVERT_M)
#define AK8975_CONVERT_M_Z                 (-AK8975_CONVERT_M)

#define AK8975_CONVERT_O                   (1.0f/64.0f)
#define AK8975_CONVERT_O_A                 (AK8975_CONVERT_O)
#define AK8975_CONVERT_O_P                 (AK8975_CONVERT_O)
#define AK8975_CONVERT_O_R                 (-AK8975_CONVERT_O)

/* conversion of acceleration data to SI units (m/s^2) */
/* 720 LSB = 1G */
#define AKSC_LSG					(720.0f)
//#define CONVERT_A					CONVERT_AKM_G

/* conversion of magnetic data to uT units */
//#define CONVERT_M					(0.06f)

/* conversion of orientation data (Q6) to degree units */
#define CONVERT_OR					(1.0f / 64.0f)
/* conversion of rotation vector (Q14) data to float */
//#define CONVERT_RV					CONVERT_Q14

#define SENSOR_STATE_MASK           (0x7FFF)

/*****************************************************************************/

__END_DECLS

#endif  // ANDROID_SENSORS_H