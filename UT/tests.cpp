/* tests.cpp */
#include "../nominate.cpp"
#include <gtest/gtest.h>
 
TEST(Election, ElectonOne) { 
    contenders c;

    ASSERT_EQ(0, c.listcontenders());
    ASSERT_EQ(1, c.nominate("Abhishek"));
    ASSERT_EQ(1, c.listcontenders());
    ASSERT_EQ(1, c.nominate("Raghav"));
    ASSERT_EQ(1, c.listcontenders());


    ASSERT_EQ(0, c.listmanifesto());
    ASSERT_EQ(1, c.manifesto("Vineet", "manifesto1", "idea1", "idea2", "idea3"));
    ASSERT_EQ(1, c.listmanifesto());
    ASSERT_EQ(1, c.manifesto("Ravi", "manifesto2", "idea4", "idea5", "idea6"));
    ASSERT_EQ(1, c.listmanifesto());
    ASSERT_EQ(1, c.manifesto("Vijay", "manifesto3", "idea6", "idea7", "idea8"));
    ASSERT_EQ(1, c.listmanifesto());


    ASSERT_EQ(0, c.listRatings());
    ASSERT_EQ(1,c.rateIdea((char*)"idea1", (char*)"Abhishek", (char*)"Aditya", 6));
    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1,c.rateIdea((char*)"idea2", (char*)"Abhishek", (char*)"Manish", 6));
    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1,c.rateIdea((char*)"idea4", (char*)"Ravi", (char*)"Suresh", 6));
    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1,c.rateIdea((char*)"idea7", (char*)"Vijay", (char*)"Mahesh", 6));
    ASSERT_EQ(1, c.listRatings());


    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1, c.deleteRating((char*)"idea7", (char*)"Vijay", (char*)"Mahesh"));
    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1, c.deleteRating((char*)"idea4", (char*)"Ravi", (char*)"Suresh"));
    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1, c.deleteRating((char*)"idea2", (char*)"Abhishek", (char*)"Manish"));
    ASSERT_EQ(1, c.listRatings());
    ASSERT_EQ(1, c.deleteRating((char*)"idea1", (char*)"Abhishek", (char*)"Aditya"));
    ASSERT_EQ(0, c.listRatings());


}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
