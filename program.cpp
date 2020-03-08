#include <nominate.cpp>

int main(int argc, char** argv)
{
	contenders c;

	c.nominate("abhishek");
	c.listcontenders();
	c.nominate("anuj");
	c.listcontenders();

	c.manifesto("abhishek", "mani", "idea1", "idea2", "idea3");
	c.listmanifesto();
	c.manifesto("tiwari", "mani", "idea1", "idea2", "idea3");
	c.listmanifesto();

	c.rateIdea((char*)"idea1", (char*)"abhishek", (char*)"tiwari", 6);
	c.listRatings();
	c.rateIdea((char*)"idea2", (char*)"abhishek", (char*)"tiwari", 6);
	c.listRatings();
	c.deleteRating((char*)"idea1", (char*)"abhishek", (char*)"tiwari");
	c.listRatings();
	c.deleteRating((char*)"idea2", (char*)"abhishek", (char*)"tiwari");
	c.listRatings();
}
