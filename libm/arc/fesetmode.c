/* Install given floating-point control modes.
   Copyright (C) 2020-2025 Free Software Foundation, Inc.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <https://www.gnu.org/licenses/>.  */

#include <fenv.h>
#include "fpu_control.h"

int
fesetmode (const femode_t *modep)
{
  unsigned int fpcr;

  if (modep == FE_DFL_MODE)
    {
      fpcr = _FPU_DEFAULT;
    }
  else
    {
      /* No need to mask out reserved bits as they are IoW.  */
      fpcr = *modep;
    }

  _FPU_SETCW (fpcr);

  return 0;
}
