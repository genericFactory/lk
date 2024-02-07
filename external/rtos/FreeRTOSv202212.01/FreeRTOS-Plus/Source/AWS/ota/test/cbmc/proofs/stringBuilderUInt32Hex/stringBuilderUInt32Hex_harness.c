/*
 * AWS IoT Over-the-air Update v3.4.0
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file stringBuilderUInt32Hex_harness.c
 * @brief Implements the proof harness for stringBuilderUInt32Hex function.
 */

#include <stdlib.h>

/* Include files required for mqtt interface. */
#include "ota_mqtt_private.h"

/* Maximum number of output digits of an unsigned long value. */
#define U32_MAX_LEN    10U

/* Declaration of the mangled name function generated by CBMC for static functions. */
size_t __CPROVER_file_local_ota_mqtt_c_stringBuilderUInt32Hex( char * pBuffer,
                                                               size_t bufferSizeBytes,
                                                               uint32_t value );

void stringBuilderUInt32Hex_harness()
{
    char * pBuffer;
    size_t bufferSizebytes;
    uint32_t value;

    /* The bufferSizebytes is the size of the pBuffer. The pBuffer is statically initialized with
     * a size of U32_MAX_LEN + 1 in all the functions which call stringBuilderUInt32Decimal. Hence,
     * the size can never be below that. */
    __CPROVER_assume( bufferSizebytes > U32_MAX_LEN );

    pBuffer = ( char * ) malloc( bufferSizebytes * sizeof( char ) );

    /* pBuffer is always initialized statically before passing it to the function. Hence,
     * it can never be NULL. */
    __CPROVER_assume( pBuffer != NULL );

    ( void ) __CPROVER_file_local_ota_mqtt_c_stringBuilderUInt32Hex( pBuffer, bufferSizebytes, value );

    free( pBuffer );
}