#include <gtest/gtest.h>
#include "../Task/TextFunctions.h"
//part_1
TEST(Task_3_SUM, Test_1) {
    char input[] = "123456";
    ASSERT_EQ(-3, findSum(input, strlen(input)));
}

TEST(Task_3_SUM, Test_2) {
    char input[] = "";
    ASSERT_EQ(0, findSum(input, strlen(input)));
}
TEST(Task_3_SUM, Test_3) {
    char input[] = "1234569366w67868w6564q4629q846962946269q83";
    ASSERT_EQ(2, findSum(input, strlen(input)));
}

TEST(Task_3_SUM, Test_4) {
    char input[] = "";
    ASSERT_EQ(0, findSum(input, strlen(input)));
}
TEST(Task_3_SUM, Test_5) {
    char input[] = "11111111111111111111111111-11111111111111111";
    ASSERT_EQ(1, findSum(input, strlen(input)));
}

TEST(Task_3_SUM, Test_6) {
    char input[] = "-12llllllllllllllllllllllllllllllllllllllllllll 232323";
    ASSERT_EQ(4, findSum(input, strlen(input)));
}
TEST(Task_3_SUM, Test_7) {
    char input[] = "00009099992209424o2o4o24o24o2o42o4o2";
    ASSERT_EQ(14, findSum(input, strlen(input)));
}

TEST(Task_3_SUM, Test_8) {
    char input[] = "][]][][][2]3[2]3[]2[3]2[3]2[3][23][2]3[2][3]2[3]2[3][2]3[2][3-2323-23-2p3-p2-3p2-p3-2p3-23-23-p2-";
    ASSERT_EQ(-19, findSum(input, strlen(input)));
}
TEST(Task_3_SUM, Test_9) {
    char input[] = "1";
    ASSERT_EQ(1, findSum(input, strlen(input)));
}

TEST(Task_3_SUM, Test_10) {
    char input[] = "0-1";
    ASSERT_EQ(-1, findSum(input, strlen(input)));
}

//part_2
int second_ceck(char* input_1) {

    char* input = (char*)malloc(sizeof(char) * strlen(input_1));
    for (int i = 0; i < strlen(input_1); i++) {
        input[i] = input_1[i];
    }
    std::pair<int, char** > result = findWorld(input, strlen(input));
    int size = result.first;
    for (int i = 0; i < result.first; i++) {
        delete[] result.second[i];
    }
    delete[] result.second;
    return size;

}

TEST(Task_3_SUM_2, TestSec_1) {
    char input[] = "a a a a a a a a a a a a";
    ASSERT_EQ(12, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_2) {
    char input[] = "";
    ASSERT_EQ(0, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_3) {
    char input[] = "a a a a a a a a a a a a  j j jjos d dnjsndksnd s djs d sju djs dk ad akd ajkd kas da kd ka dk dj asjdk akd kas dk ajkd akd";
    ASSERT_EQ(18, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_4) {
    char input[] = "qdqdwqdwdwedwdwd";
    ASSERT_EQ(0, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_5) {
    char input[] = "non non non non";
    ASSERT_EQ(4, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_6) {
    char input[] = "cnvmc ,cvnc,v cc,vn,cnvn c,v,cnv,n c,nv,cnv c,vnc,vn";
    ASSERT_EQ(1, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_7) {
    char input[] = "a a pspfpsopfospfosdf sdfkpspfsdkfpksf sfmsfsdfkskfsfslfskdlfksldfs flsmflms";
    ASSERT_EQ(3, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_8) {
    char input[] = "a fgafg fgagg ggagg agg gg gg";
    ASSERT_EQ(3, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_9) {
    char input[] = "-1 1 2 3 4 5 6 7 8 9";
    ASSERT_EQ(9, second_ceck(input));
}
TEST(Task_3_SUM_2, TestSec_10) {
    char input[] = "rsr ------ tst";
    ASSERT_EQ(3, second_ceck(input));
}




//part_3
TEST(Task_3_SUM_3, TestFirst_1) {
    char input[] = "olrjfjf rfnirnirf rfnrnforfrfokrfokrofkrf rfkrmforkfokorf -r f-r -rf-r-fr-f r-r";
    ASSERT_EQ(3, inWichWorld(input, strlen(input), 27));
}

TEST(Task_3_SUM_3, TestFirst_2) {
    char input[] = "";
    ASSERT_EQ(-1, inWichWorld(input, strlen(input), 27));
}
TEST(Task_3_SUM_3, TestFirst_3) {
    char input[] = "olrjfjf rfnirnirjkhhhhhhf shf sdjf lsfhsdlfhkjsflsdlfhsldfhlsf kjhfnshfhdfh d jfjdfjdhfjdj dfjd h  hs lkhfsdkfh slkfh slfjhdslfgsljfh lfh lshfjlshfljshflj sljf hslf hokorf -r f-r -rf-r-fr-f r-r";
    ASSERT_EQ(17, inWichWorld(input, strlen(input), 156));
}

TEST(Task_3_SUM_3, TestFirst_4) {
    char input[] = "1dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd----------------]aa                                                             333333333333333333333333333333333";
    ASSERT_EQ(1, inWichWorld(input, strlen(input), 56));
}
TEST(Task_3_SUM_3, TestFirst_5) {
    char input[] = "oejfeo  fej jfefjojifjj h hh h h h h h hh hj j j j j j jk k k l l l kjhg f gh jk kl po yi ygy g uf ft f fb db drd td ty tyv v     -rf-r-fr-f r-r";
    ASSERT_EQ(5, inWichWorld(input, strlen(input), 27));
}

TEST(Task_3_SUM_3, TestFirst_6) {
    char input[] = "                                                                                   ";
    ASSERT_EQ(0, inWichWorld(input, strlen(input), 23));
}
TEST(Task_3_SUM_3, TestFirst_7) {
    char input[] = "skmfffffffffffffffffffffffffffffffffff kwfkmwlmflmw mwflm wlmfm mwlmfw fh d jfjdfjdhfjdj dfjd h  hs lkhfsdkfh slkfh slfjhdslfgsljfh lfh lshfjlshfljshflj sljf hslf hokorf -r f-r -rf-r-fr-f r-r";
    ASSERT_EQ(15, inWichWorld(input, strlen(input), 134));
}

TEST(Task_3_SUM_3, TestFirst_8) {
    char input[] = "1ddddddddddddddddddddddd wfwmmklwmlkmfmwm klf  lkwmwlkfmlwfk - - - 0 0 0 0 00 00 0 00 0 0 0 00  00 ---------------]aa                                                      333333; ;;;;;'''d;;v;'f;'f;'rf;'r;";
    ASSERT_EQ(11, inWichWorld(input, strlen(input), 78));
}
TEST(Task_3_SUM_3, TestFirst_9) {
    char input[] = "skmfffscsc=-s-c=s-=-=s- -= -=-= -= - -  =- =-= -= - = -=- =-= -  p[ ; [vkioe ehuh uiefegfoeofh hposu g ffff lmw mwflm wlmfm mwlmfw fh d jfjdfjdhfjdj dfjd h  hs lkhfsdkfh slkfh slfjhdslfgsljfh lfh lshfjlshfljshflj sljf hslf hokorf -r f-r -rf-r-fr-f r-r";
    ASSERT_EQ(8, inWichWorld(input, strlen(input), 45));
}

TEST(Task_3_SUM_3, TestFirst_10) {
    char input[] = "1d27472492472847dhfdh dj ksfsjksslkg kwmwlkfmlwfk - - - 0 0 'sfs;'fs;'f;'s;'f;s'f;' ------]aa                                                      3sldf jsfh lsgf ksdlgfgsl sgf sfrf;'r;";
    ASSERT_EQ(-1, inWichWorld(input, strlen(input), 2049));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}