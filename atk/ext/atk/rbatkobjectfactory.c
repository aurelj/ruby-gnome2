/* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
/*
 *  Copyright (C) 2011  Ruby-GNOME2 Project Team
 *  Copyright (C) 2003  Masao Mutoh
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA  02110-1301  USA
 */

#include "rbatkprivate.h"

#define RG_TARGET_NAMESPACE cObjectFactory
#define _SELF(s) (RVAL2ATKOBJECTFACTORY(s))

static VALUE
rg_create_accessible(VALUE self, VALUE obj)
{
    return GOBJ2RVAL(atk_object_factory_create_accessible(_SELF(self), RVAL2GOBJ(obj)));
}

static VALUE
rg_accessible_type(VALUE self)
{
    return GTYPE2CLASS(atk_object_factory_get_accessible_type(_SELF(self)));
}

static VALUE
rg_invalidate(VALUE self)
{
    atk_object_factory_invalidate(_SELF(self));
    return self;
}

void
Init_atk_objectfactory(VALUE mAtk)
{
    VALUE RG_TARGET_NAMESPACE = G_DEF_CLASS(ATK_TYPE_OBJECT_FACTORY, "ObjectFactory", mAtk);
    RG_DEF_METHOD(create_accessible, 0);
    RG_DEF_METHOD(accessible_type, 0);
    RG_DEF_METHOD(invalidate, 0);
}
