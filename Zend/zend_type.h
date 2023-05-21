/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Zend Technologies Ltd. (http://www.zend.com)           |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Ben Ramsey <ramsey@php.net>                                 |
   +----------------------------------------------------------------------+
*/

#ifndef ZEND_TYPE_H
#define ZEND_TYPE_H

#include "zend.h"

#include <stdint.h>

BEGIN_EXTERN_C()

extern ZEND_API zend_object_handlers zend_type_object_handlers;
extern ZEND_API zend_class_entry *zend_ce_type;

void zend_register_type_ce(void);
void zend_type_add_interfaces(zend_class_entry *ce);

void zend_type_register_handlers(zend_class_entry *ce);
void zend_type_register_props(zend_class_entry *ce);

END_EXTERN_C()

#endif /* ZEND_TYPE_H */
