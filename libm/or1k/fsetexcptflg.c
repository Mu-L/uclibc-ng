/* Set floating-point environment exception handling.
   Copyright (C) 2024-2025 Free Software Foundation, Inc.

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

int
fesetexceptflag (const fexcept_t *flagp, int excepts)
{
  fpu_control_t cw;
  fpu_control_t cw_new;

  /* Get the current exceptions.  */
  _FPU_GETCW (cw);

  /* Make sure the flags we want restored are legal.  */
  excepts &= FE_ALL_EXCEPT;

  /* Now set selected bits from flagp. Note that we ignore all non-flag
     bits from *flagp, so they don't matter.  */
  cw_new = (cw & ~excepts) | (*flagp & excepts);

  if (cw != cw_new)
    _FPU_SETCW (cw_new);

  /* Success.  */
  return 0;
}
