#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  PythonForHemmy.py
#  
#  Copyright 2020 tenzi <tenzi@LAPTOP-U355A8BD>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  


def main(args):
		sum = 1
		factorial = 1
		for i in range(1, 10):
				factorial *= i
				sum = sum + (1 / factorial)
		print(sum)
		return 0

if __name__ == '__main__':
		import sys
		sys.exit(main(sys.argv))
