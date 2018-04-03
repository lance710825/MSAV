/****************************************************************************
**
** Copyright (C) Qxt Foundation. Some rights reserved.
**
** This file is part of the QxtCore module of the Qxt library.
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of the Common Public License, version 1.0, as published by
** IBM.
**
** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
** FITNESS FOR A PARTICULAR PURPOSE.
**
** You should have received a copy of the CPL along with this file.
** See the LICENSE file and the cpl1.0.txt file included with the source
** distribution for more information. If you did not receive a copy of the
** license, contact the Qxt Foundation.
**
** <http://libqxt.org>  <foundation@libqxt.org>
**
****************************************************************************/

/****************************************************************************
** This file is derived from code bearing the following notice:
** The sole author of this file, Adam Higerd, has explicitly disclaimed all
** copyright interest and protection for the content within. This file has
** been placed in the public domain according to United States copyright
** statute and case law. In jurisdictions where this public domain dedication
** is not legally recognized, anyone who receives a copy of this file is
** permitted to use, modify, duplicate, and redistribute this file, in whole
** or in part, with no restrictions or conditions. In these jurisdictions,
** this file shall be copyright (C) 2006-2008 by Adam Higerd.
****************************************************************************/
#ifndef MSAV_DPTR_H
#define MSAV_DPTR_H

#define DPTR_DECLARE_PRIVATE(Class) friend class Class##Private; DptrPrivateInterface<Class, Class##Private> dptr_d;
#define DPTR_DECLARE_PUBLIC(Class) friend class Class;
#define DPTR_INIT_PRIVATE(Class) qxt_d.setPublic(this);
#define DPTR_D(Class) Class##Private& d = dptr_d()
#define DPTR_P(Class) Class& p = dptr_p()

template <typename PUB>
class DptrPrivate
{
public:
    virtual ~DptrPrivate() {}
    inline void setPublic(PUB* pub) {ptr = pub;}
protected:
    inline PUB& dptr_p() {return *ptr;}
    inline const PUB& dptr_p() const {return *ptr;}
private:
    PUB* ptr;
};

template <typename PUB, typename PVT>
class DptrPrivateInterface
{
    friend class DptrPrivate<PUB>;
public:
    DptrPrivateInterface() { pvt = new PVT; }
    ~DptrPrivateInterface() { delete pvt; }
    inline void setPublic(PUB* pub) { pvt->setPublic(pub); }
    inline PVT& operator()() { return *static_cast<PVT*>(pvt); }
    inline const PVT& operator()() const { return *static_cast<PVT*>(pvt); }
private:
    DptrPrivate<PUB>* pvt;
};

#endif //MSAV_DPTR_H
