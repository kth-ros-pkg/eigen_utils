/*
 *  eigen_utils.cpp
 *
 *
 *  Created on: Jan 14, 2014
 *  Authors:   Francisco Viña
 *            fevb <at> kth.se
 */

/* Copyright (c) 2014, Francisco Viña, CVAP, KTH
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of KTH nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL KTH BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include <eigen_utils/eigen_utils.h>


Matrix3d eigen_utils::projMatrix(const Vector3d &vec)
{
	Matrix3d proj_matrix = vec*vec.transpose();

	return proj_matrix;
}

Matrix3d eigen_utils::orthProjMatrix(const Vector3d &vec)
{
	Matrix3d orth_proj_matrix = Matrix3d::Identity() - vec*vec.transpose();
	return orth_proj_matrix;
}


Matrix3d eigen_utils::skewSymmetric(const Vector3d &vec)
{
	Matrix3d ss_matrix = Matrix3d::Zero();

	ss_matrix(0,1) = -vec(2);
	ss_matrix(0,2) = vec(1);

	ss_matrix(1,0) = vec(2);
	ss_matrix(1,2) = -vec(0);

	ss_matrix(2,0) = -vec(1);
	ss_matrix(2,1) = vec(0);


	return ss_matrix;
}
