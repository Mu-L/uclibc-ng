/* Install given floating-point control modes.  SH4 version.
   Copyright (C) 2016-2025 Free Software Foundation, Inc.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <fenv.h>
#include <fpu_control.h>

#define FPU_STATUS 0x3f07c

int
fesetmode (const femode_t *modep)
{
  fpu_control_t fpscr;

  _FPU_GETCW (fpscr);
  fpscr &= FPU_STATUS;
  if (modep == FE_DFL_MODE)
    fpscr |= _FPU_DEFAULT;
  else
    fpscr |= *modep & ~FPU_STATUS;
  _FPU_SETCW (fpscr);

  return 0;
}
