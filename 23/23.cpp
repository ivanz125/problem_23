#include "stdafx.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "ChatRoom.h"

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);
	system("pause");
	return 0;
}

TEST_CASE("Users"){
	ChatRoom* chat = new ChatRoom();
	User userOne("First", chat);
	User userTwo("Second", chat);
	User userThree("Third", chat);

	CHECK(userOne.getId() == 0);
	CHECK(userOne.getName().compare("First") == 0);
	CHECK(userTwo.getId() == 1);
	CHECK(userTwo.getName().compare("Second") == 0);
	CHECK(userThree.getId() == 2);
	CHECK(userThree.getName().compare("Third") == 0);

	std::vector<User*> users = chat->getUsers();
	CHECK(users.size() == 3);
	CHECK(users[0]->getName().compare("First") == 0);
	CHECK(users[1]->getName().compare("Second") == 0);
	CHECK(users[2]->getName().compare("Third") == 0);
}

TEST_CASE("Messages"){
	ChatRoom* chat = new ChatRoom();
	User userOne("First", chat);
	User userTwo("Second", chat);

	userOne.sendMessage("Hello One");
	std::string lastMsg = chat->getLastMessage();
	CHECK(lastMsg.compare("Hello One") == 0);
	CHECK(chat->getLastMessageUserId() == 0);

	userOne.sendMessage("Hello One Again");
	lastMsg = chat->getLastMessage();
	CHECK(lastMsg.compare("Hello One Again") == 0);
	CHECK(chat->getLastMessageUserId() == 0);

	userTwo.sendMessage("Hello Two");
	lastMsg = chat->getLastMessage();
	CHECK(lastMsg.compare("Hello Two") == 0);
	CHECK(chat->getLastMessageUserId() == 1);
}