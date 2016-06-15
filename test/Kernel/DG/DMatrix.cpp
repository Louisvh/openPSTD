//////////////////////////////////////////////////////////////////////////
// This file is part of openPSTD.                                       //
//                                                                      //
// openPSTD is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU General Public License as published by //
// the Free Software Foundation, either version 3 of the License, or    //
// (at your option) any later version.                                  //
//                                                                      //
// openPSTD is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of       //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        //
// GNU General Public License for more details.                         //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with openPSTD.  If not, see <http://www.gnu.org/licenses/>.    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Date: 1-6-2016
//
//
// Authors: M. R. Fortuin
//
//
// Purpose:
//
//
//////////////////////////////////////////////////////////////////////////

#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif

#include <boost/test/unit_test.hpp>
#include <kernel/DG/DMatrix.h>

using namespace OpenPSTD::Kernel::DG;
using namespace std;
using namespace Eigen;

BOOST_AUTO_TEST_SUITE(DG)
    BOOST_AUTO_TEST_SUITE(D_Matrix)
        BOOST_AUTO_TEST_CASE(DMatrix_1D_2) {
            int N = 3;
            VectorX<double> r(N+1);
            MatrixX<double> V(N+1, N+1);
            MatrixX<double> DrExpected(N+1,N+1);

            r <<
            -1.000000000000000,
            -0.447213595499958,
            0.447213595499958,
            1.000000000000000;

            V <<
            0.707106781186547,  -1.224744871391589,   1.581138830084190,  -1.870828693386972,
            0.707106781186547,  -0.547722557505166,  -0.316227766016838,   0.836660026534076,
            0.707106781186547,   0.547722557505166,  -0.316227766016838,  -0.836660026534076,
            0.707106781186547,   1.224744871391589,   1.581138830084190,   1.870828693386972;

            DrExpected <<
            -2.999999999999999,   4.045084971874736,  -1.545084971874736,   0.500000000000000,
            -0.809016994374947,  -0.000000000000000,   1.118033988749895,  -0.309016994374947,
             0.309016994374947,  -1.118033988749895,   0.000000000000000,   0.809016994374947,
            -0.500000000000000,   1.545084971874736,  -4.045084971874735,   2.999999999999999;

            MatrixX<double> Dr = DMatrix1D<double>(N, r, V);
            BOOST_CHECK(Dr.isApprox(DrExpected));
        }

        BOOST_AUTO_TEST_CASE(DMatrix_1D_6) {
            int N = 6;
            VectorX<double> r(N+1);
            MatrixX<double> V(N+1, N+1);
            MatrixX<double> DrExpected(N+1,N+1);

            r <<
                -1.000000000000000,
                -0.830223896278567,
                -0.468848793470714,
                 0.000000000000000,
                 0.468848793470714,
                 0.830223896278567,
                 1.000000000000000;

            V <<
                0.707106781186547	,	-1.224744871391580	,	1.581138830084190	,	-1.870828693386970	,	2.121320343559640	,	-2.345207879911710	,	2.549509756796390	,
                0.707106781186547	,	-1.016812459073910	,	0.844182001556940	,	-0.346643573228288	,	-0.278372647949331	,	0.807538898284274	,	-1.057410345369820	,
                0.707106781186547	,	-0.574220155261391	,	-0.269222426980870	,	0.833675471702112	,	-0.504704283282048	,	-0.365166265456773	,	0.846707059684174	,
                0.707106781186547	,	0.000000000000000	,	-0.790569415042095	,	0.000000000000000	,	0.795495128834866	,	0.000000000000000	,	-0.796721798998873	,
                0.707106781186547	,	0.574220155261392	,	-0.269222426980870	,	-0.833675471702112	,	-0.504704283282048	,	0.365166265456773	,	0.846707059684174	,
                0.707106781186547	,	1.016812459073910	,	0.844182001556939	,	0.346643573228285	,	-0.278372647949334	,	-0.807538898284277	,	-1.057410345369820	,
                0.707106781186547	,	1.224744871391580	,	1.581138830084190	,	1.870828693386970	,	2.121320343559640	,	2.345207879911710	,	2.549509756796390	;


            DrExpected <<
                    -10.500000000000000	,	14.201576602919800	,	-5.668985225545480	,	3.199999999999980	,	-2.049964813076730	,	1.317373435702430	,	-0.500000000000000	,
                    -2.442926014244290	,	0.000000000000015	,	3.455828214294280	,	-1.598606688098360	,	0.961339797288713	,	-0.602247179635786	,	0.226611870395445	,
                     0.625256665515344	,	-2.215804283169970	,	-0.000000000000005	,	2.266698087086000	,	-1.066441904006370	,	0.616390835517580	,	-0.226099400942575	,
                    -0.312500000000001	,	0.907544471268821	,	-2.006969240588750	,	-0.000000000000002	,	2.006969240588750	,	-0.907544471268821	,	0.312500000000000	,
                     0.226099400942575	,	-0.616390835517579	,	1.066441904006370	,	-2.266698087085990	,	0.000000000000000	,	2.215804283169970	,	-0.625256665515342	,
                    -0.226611870395445	,	0.602247179635786	,	-0.961339797288713	,	1.598606688098360	,	-3.455828214294280	,	0.000000000000006	,	2.442926014244280	,
                     0.500000000000002	,	-1.317373435702430	,	2.049964813076740	,	-3.199999999999990	,	5.668985225545510	,	-14.201576602919800	,	10.499999999999900	;


            MatrixX<double> Dr = DMatrix1D<double>(N, r, V);
            BOOST_CHECK(Dr.isApprox(DrExpected));
        }
    BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()
