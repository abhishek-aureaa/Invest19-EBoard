/* tests.cpp */
#include "../nominate.cpp"
#include <gtest/gtest.h>
 
TEST(Election, ElectonOne) { 

	printf("*********************************************************\n");
	printf("************************UNIT TESTING - START*********************\n");
	printf("*********************************************************\n");
	contenders c;

	ASSERT_EQ(0,c.listcontenders());
	ASSERT_EQ(1,c.nominate("Vineet"));
	ASSERT_EQ(1,c.listcontenders());
	ASSERT_EQ(1,c.nominate("Ravi"));
	ASSERT_EQ(1,c.listcontenders());
	ASSERT_EQ(1,c.nominate("Vijay"));	
	ASSERT_EQ(1,c.listcontenders());


        ASSERT_EQ(0, c.listmanifesto());
	ASSERT_EQ(1, c.manifesto("Vineet", "manifesto1", "idea1", "idea2", "idea3"));
        ASSERT_EQ(1, c.listmanifesto());
	ASSERT_EQ(1, c.manifesto("Ravi", "manifesto2", "idea4", "idea5", "idea6"));
        ASSERT_EQ(1, c.listmanifesto());
	ASSERT_EQ(1, c.manifesto("Vijay", "manifesto3", "idea7", "idea8", "idea9"));
        ASSERT_EQ(1, c.listmanifesto());


        ASSERT_EQ(0, c.listRatings());
	ASSERT_EQ(1,c.rateIdea((char*)"idea1", (char*)"Vineet", (char*)"Aditya", 6));
        ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1,c.rateIdea((char*)"idea2", (char*)"Vineet", (char*)"Manish", 6));
        ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1,c.rateIdea((char*)"idea4", (char*)"Ravi", (char*)"Suresh", 6));
        ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1,c.rateIdea((char*)"idea7", (char*)"Vijay", (char*)"Mahesh", 6));
        ASSERT_EQ(1, c.listRatings());


	ASSERT_EQ(1, c.listFollowersForContender((char*)"Vineet"));
	ASSERT_EQ(1, c.addFollower((char*)"Vineet", (char*)"Akhilesh"));
	ASSERT_EQ(1, c.listFollowersForContender((char*)"Vineet"));
	ASSERT_EQ(1, c.addFollower((char*)"Vineet", (char*)"Vikram"));
	ASSERT_EQ(1, c.listFollowersForContender((char*)"Vineet"));

	ASSERT_EQ(1, c.listFollowersForContender((char*)"Ravi"));
	ASSERT_EQ(1, c.addFollower((char*)"Ravi", (char*)"Sumanth"));
	ASSERT_EQ(1, c.listFollowersForContender((char*)"Ravi"));

	ASSERT_EQ(1, c.listFollowersForContender((char*)"Vijay"));
	ASSERT_EQ(1, c.addFollower((char*)"Vijay", (char*)"Jitendra"));
	ASSERT_EQ(1, c.listFollowersForContender((char*)"Vijay"));

	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.deleteRating((char*)"idea7", (char*)"Vijay", (char*)"Mahesh"));
	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.deleteRating((char*)"idea4", (char*)"Ravi", (char*)"Suresh"));
	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.deleteRating((char*)"idea2", (char*)"Vineet", (char*)"Manish"));
	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.deleteRating((char*)"idea1", (char*)"Vineet", (char*)"Aditya"));
	ASSERT_EQ(0, c.listRatings());

	ASSERT_EQ(0, c.listFollowersForContender((char*)"Aditya"));
	ASSERT_EQ(1, c.rateIdea((char*)"idea1", (char*)"Aditya", (char*)"Naresh", 6));
	ASSERT_EQ(1, c.addFollower((char*)"Aditya", (char*)"Naveen"));
	ASSERT_EQ(1, c.listFollowersForContender((char*)"Aditya"));
	ASSERT_EQ(1, c.MailToContender((char*)"Vineet"));


	ASSERT_EQ(1, c.listmanifesto());
	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.rateIdea((char*)"idea1", (char*)"Vineet", (char*)"Aditya", 6));
	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.postAnIdea((char*)"Vineet", (char*)"idea10"));
	ASSERT_EQ(1, c.listmanifesto());



	ASSERT_EQ(0, c.postAnIdea((char*)"Ritesh", (char*)"idea10"));
	ASSERT_EQ(1, c.listRatings());
	ASSERT_EQ(1, c.listmanifesto());

	printf("*********************************************************\n");
	printf("************************UNIT TESTING - ENDS *********************\n");
	printf("*********************************************************\n");

}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
