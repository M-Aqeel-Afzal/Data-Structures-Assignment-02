
#include"pch.h"
//#include "gtest/gtest.h"
#include"../Assignment_02/D_I190650.h"
using namespace std;
TEST(SearchTest, CBID) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    string s1 = "joe frank m 44 downing street british murder life in prison - 123456 Vodafone 12/04/2010 12/04/2020 unactive";
    EXPECT_TRUE(s1 == db.CBID_Search_by_CNIC(3740));

}

TEST(SearchTest, CCID) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    string s1 = "Halsey Palmer f 11 Ann Street british burglary 6 years in prison 7000 323485 EE 12/12/2017 12/12/2027 active";

    EXPECT_TRUE(db.CCID_Search_by_CNIC(5960) == s1);

}

TEST(SearchTest, CCND) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    string s1 = "Hollace Dudley f 1 Ann Street british 423470 Skymobile 12/1/2000 12/1/2010 unactive";

    EXPECT_TRUE(db.CCND_Search_by_CNIC(6287) == s1);

}


TEST(UpdateTest, CBID_Name) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.updateCBIDName("Alice", 9831) == 1);
    EXPECT_TRUE(db.updateCBIDName("Doc", 9832) == 0);

}

TEST(UpdateTest, CBID_FName) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.updateCBIDFName("Kevin", 9177) == 1);
    EXPECT_TRUE(db.updateCBIDFName("Steve", 1234) == 0);

}

TEST(UpdateTest, CBID_Address) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.updateCBIDAddress("12 Ann Street", 8372) == 1);
    EXPECT_TRUE(db.updateCBIDAddress("21 Downing Street", 9639) == 0);

}

TEST(UpdateTest, CBID_Nationality) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.updateCBIDNationality("Alien", 8000) == 0);
    EXPECT_TRUE(db.updateCBIDNationality("Alien", 9832) == 0);

}

TEST(CrimeAddTest, CCID) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.addCrime(7564, "Robbery", "2 years in prison", "1000") == 1);

    EXPECT_TRUE(db.addCrime(8099, "Kidnapping", "20 years in prison", "2000") == 0);
}


TEST(CrimeDeleteTest, CCID) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.deleteCrime(5960, "burglary", "6 years in prison", "7000") == 1);

    EXPECT_TRUE(db.deleteCrime(4064, "murder", "2 years in prison", "10000") == 0);
}

TEST(CrimeUpdateTest, CCID) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    EXPECT_TRUE(db.updateCrime(5960, "murder", "20 years in prison", "10000") == 1);

    EXPECT_TRUE(db.updateCrime(9630, "murder", "20 years in prison", "10000") == 0);
}

TEST(addNumber, CCND) {
    /*Aslo try adding 5th number in database against CNIC, it should limit to max 4 numbers. Refer to CCND point 'v'*/
    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    ASSERT_TRUE(db.addNumber(9630, 123480) == 2);

}



TEST(checkRegistred_No, CCND) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    ASSERT_TRUE(db.checkRegistred_No(4305) == 4);

    ASSERT_TRUE(db.checkRegistred_No(9662) == 1);

    ASSERT_TRUE(db.checkRegistred_No(9630) == 0);

}


TEST(PrintCount, CCND) {

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");

    ASSERT_TRUE(db.printcount() == 54);

}
TEST(declearAlien, t1) {         // declearing alien

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");
    string s2 = "Halsey Palmer f 11 Ann Street Alien burglary 6 years in prison 7000 323485 EE 12/12/2017 26/10/2020 unactive";
    EXPECT_TRUE(s2 == db.declareAlien(5960));


}

TEST(declearAlien, t2) {    //declearing alien and also displaying values in stack AD

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");
    string s1 = "joe frank m 44 downing street Alien murder life in prison - 123456 Vodafone 12/04/2010 26/10/2020 unactive";
    EXPECT_TRUE(s1 == db.declareAlien(3740));
    string s2 = "Halsey Palmer f 11 Ann Street Alien burglary 6 years in prison 7000 323485 EE 12/12/2017 26/10/2020 unactive";
    EXPECT_TRUE(s2 == db.declareAlien(5960));
    string s3 = "Eartha Peterson f 9 Albion Street Alien burglary 6 years in prison 10000 423469 Skymobile 17/08/2012 26/10/2020 unactive";
    EXPECT_TRUE(s3 == db.declareAlien(9662));

    cout << "\n\n All the record in stack AD\n" << endl;
    db.Display_AD();

}
TEST(verifyAlien, t) {  //verification that citizen has become Alien.
    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");
    //string s3 = "Eartha Peterson f 9 Albion Street Alien burglary 6 years in prison 10000 423469 Skymobile 17/08/2012 26/10/2020 unactive";
    db.declareAlien(9662);
    EXPECT_TRUE(db.verifyAlienDBUpdate(9662));
}



TEST(swap, CCND) {   //swapping 

    Database<string> db("CBID.txt", "CCID.txt", "CCND.txt");
    ASSERT_TRUE(db.swap(9630, 9662, "123480", "423469"));

}
