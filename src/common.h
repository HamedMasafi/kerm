/***************************************************************************
 *   Copyright (C) 2008 by Hamed Masafi   *
 *   Hamed.Masafi@GMail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef COMMON_H
#define COMMON_H

/**
	@author Hamed Masafi <Hamed.Masafi@GMail.com>
*/
class common{
public:
    common();
    ~common();

	 static const int _col_service 	=0;
	 static const int _col_rl0			=1;
	 static const int _col_rl1 		=2;
	 static const int _col_rl2			=3;
	 static const int _col_rl3			=4;
	 static const int _col_rl4			=5;
	 static const int _col_rl5			=6;
	 static const int _col_rl6			=7;
	 static const int _col_rlS			=8;
	 static const int _col_comment	=9;    
	 
	 static QString getRunlevelText(int i);
	 
};

#endif
