/* Raise given exceptions.
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
#include <fpu_control.h>
#include <float.h>
#include <math.h>

int
feraiseexcept (int excepts)
{
  unsigned int fpsr;

  /* currently raised exceptions are not cleared.  */
  _FPU_GETS (fpsr);
  fpsr |= excepts;

  _FPU_SETS (fpsr);

  return 0;
}
