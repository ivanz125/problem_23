#include <vector>
#include <string>

class User;

class ChatRoom{
	std::vector<User*> users;
	std::vector<std::string> messages;
	std::vector<int> messagesUserIds;

public:
	ChatRoom();
	void addUser(User*);
	void sendMessage(int, std::string);
	std::string getLastMessage();
	int getLastMessageUserId();
	std::vector<User*> getUsers();
};

class User{
	std::string name;
	int id;
	ChatRoom* chat;

public:
	User(std::string, ChatRoom*);
	void setId(int);
	int getId();
	std::string getName();
	void sendMessage(std::string);
};


User::User(std::string name, ChatRoom* chat){
	this->name = name;
	this->chat = chat;
	this->chat->addUser(this);
}

void User::setId(int id){
	this->id = id;
}

int User::getId(){
	return id;
}

std::string User::getName(){
	return name;
}

void User::sendMessage(std::string message){
	chat->sendMessage(id, message);
}

ChatRoom::ChatRoom(){
}

void ChatRoom::addUser(User* user){
	user->setId(users.size());
	users.push_back(user);
}

void ChatRoom::sendMessage(int userId, std::string message){
	messages.push_back(message);
	messagesUserIds.push_back(userId);
}

std::string ChatRoom::getLastMessage(){
	return messages.size() > 0 ? messages[messages.size()-1] : "";
}

int ChatRoom::getLastMessageUserId(){
	return messagesUserIds.size() > 0 ? messagesUserIds[messagesUserIds.size()-1] : -1;
}

std::vector<User*> ChatRoom::getUsers(){
	return users;
}