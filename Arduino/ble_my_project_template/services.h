/**
* This file is autogenerated by nRFgo Studio 1.21.2RC1.4
*/

#ifndef SETUP_MESSAGES_H__
#define SETUP_MESSAGES_H__

#include "hal_platform.h"
#include "aci.h"


#define SETUP_ID 0
#define SETUP_FORMAT 3 /** nRF8001 D */
#define ACI_DYNAMIC_DATA_SIZE 146

/* Service: Gap - Characteristic: Device name - Pipe: SET */
#define PIPE_GAP_DEVICE_NAME_SET          1
#define PIPE_GAP_DEVICE_NAME_SET_MAX_SIZE 7

/* Service: ParkingService - Characteristic: Free - Pipe: TX */
#define PIPE_PARKINGSERVICE_FREE_TX          2
#define PIPE_PARKINGSERVICE_FREE_TX_MAX_SIZE 1

/* Service: ParkingService - Characteristic: Free - Pipe: SET */
#define PIPE_PARKINGSERVICE_FREE_SET          3
#define PIPE_PARKINGSERVICE_FREE_SET_MAX_SIZE 1

/* Service: ParkingService - Characteristic: RegionNum - Pipe: TX */
#define PIPE_PARKINGSERVICE_REGIONNUM_TX          4
#define PIPE_PARKINGSERVICE_REGIONNUM_TX_MAX_SIZE 2

/* Service: ParkingService - Characteristic: RegionNum - Pipe: SET */
#define PIPE_PARKINGSERVICE_REGIONNUM_SET          5
#define PIPE_PARKINGSERVICE_REGIONNUM_SET_MAX_SIZE 2

/* Service: ParkingService - Characteristic: SpaceNum - Pipe: TX */
#define PIPE_PARKINGSERVICE_SPACENUM_TX          6
#define PIPE_PARKINGSERVICE_SPACENUM_TX_MAX_SIZE 2

/* Service: ParkingService - Characteristic: SpaceNum - Pipe: SET */
#define PIPE_PARKINGSERVICE_SPACENUM_SET          7
#define PIPE_PARKINGSERVICE_SPACENUM_SET_MAX_SIZE 2


#define NUMBER_OF_PIPES 7

#define SERVICES_PIPE_TYPE_MAPPING_CONTENT {\
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
}

#define GAP_PPCP_MAX_CONN_INT 0xffff /**< Maximum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_MIN_CONN_INT  0xffff /**< Minimum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_SLAVE_LATENCY 0
#define GAP_PPCP_CONN_TIMEOUT 0xffff /** Connection Supervision timeout multiplier as a multiple of 10msec, 0xFFFF means no specific value requested */

#define NB_SETUP_MESSAGES 21
#define SETUP_MESSAGES_CONTENT {\
    {0x00,\
        {\
            0x07,0x06,0x00,0x00,0x03,0x02,0x42,0x07,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x07,0x01,0x01,0x00,0x00,0x06,0x00,0x01,\
            0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x1c,0xaa,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x14,0x03,0x90,0x01,0x64,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x38,0x02,0xff,0x02,0x58,0x05,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x05,0x06,0x10,0x54,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x00,0x04,0x04,0x02,0x02,0x00,0x01,0x28,0x00,0x01,0x00,0x18,0x04,0x04,0x05,0x05,0x00,\
            0x02,0x28,0x03,0x01,0x0e,0x03,0x00,0x00,0x2a,0x04,0x14,0x07,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x1c,0x07,0x00,0x03,0x2a,0x00,0x01,0x6d,0x79,0x5f,0x70,0x72,0x6f,0x6a,0x04,0x04,0x05,\
            0x05,0x00,0x04,0x28,0x03,0x01,0x02,0x05,0x00,0x01,0x2a,0x06,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x38,0x04,0x03,0x02,0x00,0x05,0x2a,0x01,0x01,0x00,0x00,0x04,0x04,0x05,0x05,0x00,0x06,\
            0x28,0x03,0x01,0x02,0x07,0x00,0x04,0x2a,0x06,0x04,0x09,0x08,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x54,0x00,0x07,0x2a,0x04,0x01,0xff,0xff,0xff,0xff,0x00,0x00,0xff,0xff,0x04,0x04,0x02,\
            0x02,0x00,0x08,0x28,0x00,0x01,0x01,0x18,0x04,0x04,0x10,0x10,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x70,0x00,0x09,0x28,0x00,0x01,0xb8,0xd0,0x2d,0x81,0x63,0x29,0xef,0x96,0x8a,0x4d,0x55,\
            0xb3,0xaa,0xff,0xb2,0x5a,0x04,0x04,0x05,0x05,0x00,0x0a,0x28,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x8c,0x03,0x01,0x12,0x0b,0x00,0xee,0xff,0x16,0x04,0x02,0x01,0x00,0x0b,0xff,0xee,0x01,\
            0x00,0x06,0x04,0x08,0x07,0x00,0x0c,0x29,0x04,0x01,0x04,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xa8,0x00,0x00,0x01,0x00,0x00,0x46,0x14,0x03,0x02,0x00,0x0d,0x29,0x02,0x01,0x00,0x00,\
            0x04,0x04,0x05,0x05,0x00,0x0e,0x28,0x03,0x01,0x12,0x0f,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xc4,0xb1,0xba,0x16,0x04,0x03,0x02,0x00,0x0f,0xba,0xb1,0x01,0x00,0x00,0x06,0x04,0x08,\
            0x07,0x00,0x10,0x29,0x04,0x01,0x06,0x00,0x00,0x00,0x01,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xe0,0x00,0x46,0x14,0x03,0x02,0x00,0x11,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x05,0x05,\
            0x00,0x12,0x28,0x03,0x01,0x12,0x13,0x00,0xb2,0xba,0x16,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xfc,0x03,0x02,0x00,0x13,0xba,0xb2,0x01,0x00,0x00,0x06,0x04,0x08,0x07,0x00,0x14,0x29,\
            0x04,0x01,0x06,0x00,0x00,0x00,0x01,0x00,0x00,0x46,0x14,0x03,\
        },\
    },\
    {0x00,\
        {\
            0x0c,0x06,0x21,0x18,0x02,0x00,0x15,0x29,0x02,0x01,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x00,0x2a,0x00,0x01,0x00,0x80,0x04,0x00,0x03,0x00,0x00,0xff,0xee,0x01,0x00,0x82,0x04,\
            0x00,0x0b,0x00,0x0d,0xba,0xb1,0x01,0x00,0x82,0x04,0x00,0x0f,\
        },\
    },\
    {0x00,\
        {\
            0x0f,0x06,0x40,0x1c,0x00,0x11,0xba,0xb2,0x01,0x00,0x82,0x04,0x00,0x13,0x00,0x15,\
        },\
    },\
    {0x00,\
        {\
            0x13,0x06,0x50,0x00,0xb8,0xd0,0x2d,0x81,0x63,0x29,0xef,0x96,0x8a,0x4d,0x55,0xb3,0x00,0x00,0xb2,0x5a,\
        },\
    },\
    {0x00,\
        {\
            0x0f,0x06,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x06,0x06,0xf0,0x00,0x03,0x53,0x56,\
        },\
    },\
}

#endif

