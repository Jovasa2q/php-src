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

#include "zend.h"
#include "zend_API.h"
#include "zend_type_arginfo.h"
#include "zend_execute.h"

ZEND_API zend_class_entry *zend_ce_type;
ZEND_API zend_object_handlers zend_type_object_handlers;

static int zend_implement_type(zend_class_entry *interface, zend_class_entry *class_type)
{
	if (class_type->ce_flags & ZEND_ACC_TYPE) {
		return SUCCESS;
	}

	zend_error_noreturn(E_ERROR, "Non-type class %s cannot implement interface %s",
						ZSTR_VAL(class_type->name),
						ZSTR_VAL(interface->name));

	return FAILURE;
}

void zend_register_type_ce(void)
{
	zend_ce_type = register_class_TypeAlias();
	zend_ce_type->interface_gets_implemented = zend_implement_type;

	memcpy(&zend_type_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	zend_type_object_handlers.clone_obj = NULL;
	zend_type_object_handlers.compare = zend_objects_not_comparable;
}

void zend_type_add_interfaces(zend_class_entry *ce)
{
	uint32_t num_interfaces_before = ce->num_interfaces;

	ce->num_interfaces++;

	ZEND_ASSERT(!(ce->ce_flags & ZEND_ACC_RESOLVED_INTERFACES));

	ce->interface_names = erealloc(ce->interface_names, sizeof(zend_class_name) * ce->num_interfaces);

	ce->interface_names[num_interfaces_before].name = zend_string_copy(zend_ce_type->name);
	ce->interface_names[num_interfaces_before].lc_name = ZSTR_INIT_LITERAL("typealias", 0);

	ce->default_object_handlers = &zend_type_object_handlers;
}

void zend_type_register_handlers(zend_class_entry *ce)
{
	memcpy(&zend_type_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	zend_type_object_handlers.clone_obj = NULL;
	zend_type_object_handlers.compare = zend_objects_not_comparable;

	ce->default_object_handlers = &zend_type_object_handlers;
}

void zend_type_register_props(zend_class_entry *ce)
{
	ce->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES;
}
