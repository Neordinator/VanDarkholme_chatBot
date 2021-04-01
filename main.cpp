#include<iostream>
#include<string>
#include<algorithm>
#include<regex>
#include<map>

using namespace std;

map<string, string> database = {
	{
		"(hi|hello|whatsup)",
		"Do not test my patient, slave!"
	},
	{
		"what are you doing",
		"I'm going to kick your ass, little gay bitch!"
	},
	{
		"shit.*sorry",
		"Sorry for what?"
	},
	{
		"hello",
		"Get on your kneese, slave, or die with honor in battle!"
	},
	{
		"your.*name.*",
		"My name is Van. I'm boss of this Jym and I decided to be fullmaster."
	},
	{
		"how.*are.*you",
		"Well enough to kick your ass back in your backyard, boy next door!"
	},
	{
		"fuck.*you",
		"No, fuck you, letherman!"
	},
	{
		"whatsup",
		"I'm not your budy!"
	}
};

string	to_lower(string text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

void	lowerCase(string& text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);
}

void	vanSay(string text) {
	cout << "[Van]: " << text << endl;
}

string	userAsk() {
	string question;
	getline(cin, question);
	//question = to_lower(question);
	lowerCase(question);
	return question;
}

bool	battle(string& question) {
	int bossHealth = 20;
	int slaveHealth = 5;
	int faze = 0;
	bool wasStrike = false;

	vanSay("You dare to chalenge me?!");
	getline(cin, question);
	regex yesTemplate = regex(".*yes.*");
	if (regex_match(question, yesTemplate)) {
		vanSay("Get out of that leather stuff. I'll strip down out of this and we'll settle it right here in the ring!");
		cout << "\tI'll show you, who boss of this jym!" << endl;
		while (true) {
			if (faze == 0 && bossHealth > 15 && bossHealth <= 20) {
				vanSay("Show me what you can!");
				faze = 1;
			}
			getline(cin, question);
			regex punchTemplate = regex(".*punch.*");
			if (regex_match(question, punchTemplate)) {
				if (bossHealth == 20) { vanSay("Do you think that is punch?"); }
				if (faze == 1) { vanSay("argh!"); }
				if (faze == 2) { vanSay("Auch!"); }
				if (faze == 3) { vanSay("Ah-ah-augh!"); }
				if (faze == 4) { vanSay("Auch! That hurts!"); }
				bossHealth -= 1;
				wasStrike = true;
			}
			regex kickTemplate = regex(".*kick.*");
			if (regex_match(question, kickTemplate)) {
				if (bossHealth == 20) { vanSay("Now my turn to kick your ass!"); }
				if (faze == 1) { vanSay("Didn't feel anything!"); }
				if (faze == 2) { vanSay("Chhhh! Nice kick"); }
				if (faze == 3) { vanSay("Auch! That hurts!"); }
				if (faze == 4) { vanSay("Damn you!"); }
				bossHealth -= 2;
				wasStrike = true;
			}
			if (wasStrike == false) {
				if (slaveHealth == 5) { vanSay("Don't waste your words, slave!\n\t*you have been damaged*"); }
				if (slaveHealth == 4) { vanSay("Stop mumbling, slave!\n\t*you have been damaged*"); }
				if (slaveHealth == 3) { vanSay("Enough chat, worm!\n\t*you have been damaged*"); }
				if (slaveHealth == 2) { vanSay("I don't give you time for that!\n\t*you have been damaged*"); }
				if (slaveHealth == 1) { vanSay("You'r finished!\n\t*you have been damaged*"); }
				slaveHealth -= 1;
			}
			if (faze == 1 && bossHealth > 10 && bossHealth <= 15) {
				vanSay("Now you make me angry, little asswhole!");
				faze = 2;
			}
			if (faze == 2 && bossHealth > 5 && bossHealth <= 10) {
				vanSay("Let's time to get serios!");
				faze = 3;
			}
			if (faze == 3 && bossHealth > 0 && bossHealth <= 5) {
				vanSay("You are tougher then you look!");
				faze = 4;
			}
			if (slaveHealth <= 0) {
				vanSay("You are my slave now! I'll throw you in my deepest dungeon! Mua-ha-ha-ha-haaaaa!");
				cout << "\t*you have been captured and fucked right in the ass*" << endl;
				return false;
			}
			if (bossHealth <= 0) {
				vanSay("Ok, ok! I'll hide back in a dungeon and you'll never see me again...");
				cout << "\t*Congratulation! From this time you are the boss of this jym\n\t\t...for now.*" << endl;
				return true;
			}
			wasStrike = false;
		}
	}
	regex noTemplate = regex(".*no.*");
	if (regex_match(question, noTemplate)) {
		vanSay("I knew it, coward. Get out of my sight!");
		return false;
	}
}

int	main() {
	string question;

	vanSay("Hey buddy, i think you got the wrong door the leather-club is two blocks down...");

	while (true) {
		int answersCount = 0;
		question = userAsk();
		//getline(cin, question);
		//question = to_lower(question);

		for (auto entry : database) {
			//entry.first - вопрос
			//entyr.sexont - ответ
			regex regularExpression = regex(".*" + entry.first + ".*");
			if (regex_match(question, regularExpression)) {
				vanSay(entry.second);
				answersCount++;
			}
		}
		/*if (answersCount == 0) {
			cout << "What? There is nothing else to say, slave?" << endl;
		}*/
		/*if (answersCount >= 3) {
			cout << "Stop mumbling, slave!" << endl;
		}*/
		if (regex_match(question, regex(".*(challenge|fight|combat|battle).*"))) {
			if (battle(question)) { continue; }	else { goto EXIT; }
		}
		else if (regex_match(question, regex(".*(exit|run.*away|wrong.*door).*"))) {
			cout << "Get lost, coward!" << endl;
			goto EXIT;
		}
		else if (regex_match(question, regex(".*"))) {
			cout << "Stop mumbling, slave!" << endl;
		}
		/*if (regex_match(question, regex(".*exit*"))) {
			cout << "Get lost, coward!" << endl;
			goto EXIT;
		}
		else if (regex_match(question, regex(".*run.*away*"))) {
			cout << "Get lost, coward!" << endl;
			goto EXIT;
		}
		else if (regex_match(question, regex(".*hello.*"))) {
			cout << "Get lost, coward!" << endl;
			goto EXIT;
		}*/
	}
EXIT:
	cout << "\t*The End!*" << endl;
	getline(cin, question);
	return 0;
}