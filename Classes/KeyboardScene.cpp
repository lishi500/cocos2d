#include "KeyboardScene.h"
#include <iostream>
#include <string>

USING_NS_CC;
using namespace std;

Scene* KeyboardScene::createScene(){
	auto scene = Scene::create();
	auto layer = KeyboardScene::create();
	scene->addChild(layer);

	return scene;
}

bool KeyboardScene::init() {
	if (!Layer::init()) {
		return false;
	}

	label = cocos2d::Label::createWithSystemFont("Press the CTRL Key", "Arial", 22);
	label->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	this->addChild(label);

	auto eventListener = EventListenerKeyboard::create();

	Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);
	eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event * event) {
		if (keys.find(keycode)== keys.end()) {
			keys[keycode] = std::chrono::high_resolution_clock::now();
		}
	};
	eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event) {
		keys.erase(keycode);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
	this->scheduleUpdate();

	/*auto sprite = Sprite::create("smile.jpg");
	sprite->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	this->addChild(sprite);
	auto eventListener = EventListenerKeyboard::create();

	eventListener = EventListenerKeyboard::create();

	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keycode, Event*event) {
		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keycode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->setPosition(--loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->setPosition(++loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			event->getCurrentTarget()->setPosition(loc.x, --loc.y);
			break;
		}
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);*/

	return true;
}

bool KeyboardScene::isKeyPressed(EventKeyboard::KeyCode keycode) {
	if (keys.find(keycode) != keys.end()) {
		return true;
	}
	return false;
}

double KeyboardScene::keyPressedDuration(EventKeyboard::KeyCode keycode) {
	if (!isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL)) {
		return 0;
	}
	cout <<(std::chrono::high_resolution_clock::now() - keys[keycode]).count()  << endl;
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - keys[keycode]).count();
}

void KeyboardScene::update(float delta) {
	Node::update(delta);
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL)) {
		std::stringstream ss;
		ss << "Control key has been pressed for " <<
			keyPressedDuration(EventKeyboard::KeyCode::KEY_CTRL) << " ms";
		label->setString(ss.str().c_str());
	}
	else
		label->setString("Press the CTRL Key");
}
std::map<cocos2d::EventKeyboard::KeyCode,
	std::chrono::high_resolution_clock::time_point> KeyboardScene::keys;