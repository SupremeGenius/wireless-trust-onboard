/*
 *  Copyright (c) 2017 Gemalto Limited. All Rights Reserved
 *  This software is the confidential and proprietary information of GEMALTO.
 *  
 *  GEMALTO MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF 
 *  THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *  TO THE IMPLIED WARRANTIES OR MERCHANTABILITY, FITNESS FOR A
 *  PARTICULAR PURPOSE, OR NON-INFRINGEMENT. GEMALTO SHALL NOT BE
 *  LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS RESULT OF USING,
 *  MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

 *  THIS SOFTWARE IS NOT DESIGNED OR INTENDED FOR USE OR RESALE AS ON-LINE
 *  CONTROL EQUIPMENT IN HAZARDOUS ENVIRONMENTS REQUIRING FAIL-SAFE
 *  PERFORMANCE, SUCH AS IN THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT
 *  NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, DIRECT LIFE
 *  SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH THE FAILURE OF THE
 *  SOFTWARE COULD LEAD DIRECTLY TO DEATH, PERSONAL INJURY, OR SEVERE
 *  PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH RISK ACTIVITIES"). GEMALTO
 *  SPECIFICALLY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTY OF FTNESS FOR
 *  HIGH RISK ACTIVITIES;
 *
 */

#ifndef __MBEDTLS_SE_H__
#define __MBEDTLS_SE_H__

#include "SEInterface.h"

#include "mbedtls/pk.h"
#include "mbedtls/x509_crt.h"

#define MBEDTLS_ERR_SE_MIAS_SELECT_ERROR                  -0x5280  /**< Selecting mobile IAS applet failed. */
#define MBEDTLS_ERR_SE_MIAS_VERIFY_PIN_ERROR              -0x5300  /**< Verifying pin on mobile IAS applet failed. */
#define MBEDTLS_ERR_SE_MIAS_IO_ERROR                      -0x5380  /**< Transmitting apdu to mobile IAS applet failed. */
#define MBEDTLS_ERR_SE_MIAS_READ_OBJECT_ERROR             -0x5400  /**< Mobile IAS read object failed. */
#define MBEDTLS_ERR_SE_EF_VERIFY_PIN_ERROR                -0x5480  /**< Verifying pin to access EF failed. */
#define MBEDTLS_ERR_SE_EF_INVALID_NAME_ERROR              -0x5500  /**< Trying to access an EF with an invalid name. */
#define MBEDTLS_ERR_SE_EF_READ_OBJECT_ERROR               -0x5580  /**< EF read object failed. */
#define MBEDTLS_ERR_SE_BAD_KEY_NAME_ERROR                 -0x5600  /**< No matching key found with the given name. */


#define MBEDTLS_SE_EF_KEY_NAME_PREFIX       "SE://EF/"
#define MBEDTLS_SE_MIAS_KEY_NAME_PREFIX     "SE://MIAS/"
#define MBEDTLS_SE_MIAS_P11_KEY_NAME_PREFIX "SE://MIAS_P11/"

int mbedtls_se_init(SEInterface* se_iface);

int mbedtls_x509_crt_parse_se(mbedtls_x509_crt* cert, char* path, char* pin);
int mbedtls_pk_parse_se(mbedtls_pk_context* pk, char* path, char* pin);

#endif /* __MBEDTLS_SE_H__ */
