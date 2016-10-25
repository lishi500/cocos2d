#include "GraphicsScene.h"
#include <sstream>
#include <string>

USING_NS_CC;

Scene* GraphicsScene::createScene() {
	auto scene = Scene::create();
	auto Layer = GraphicsScene::create();
	scene->addChild(Layer);

	return scene;
}
bool GraphicsScene::init() {
	if (!Layer::init()) {
		return false;
	}

	auto sprite = Sprite::create("smile.jpg");
	auto sprite2 = Sprite::create("cookie.jpg");
	sprite->setAnchorPoint(Vec2(0, 0));
	//sprite2->setAnchorPoint(Vec2(0, 0));
	sprite->addChild(sprite2);

	sprite->setPosition(100, 200);
	
	sprite2->setPosition(sprite->getBoundingBox().size.width, sprite->getBoundingBox().size.height);
	Vec2 worldPosition = sprite2->convertToWorldSpace(sprite2->getPosition()); 

	std::ostringstream myString;
	myString << "Absolute Position:";
	auto label2 = Label::createWithSystemFont(std::string("aa"), "Arial", 96);
	label2->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	this->addChild(label2, 1);

	printf("%f, %f", worldPosition.x, worldPosition.y);
	this->addChild(sprite, 0);

	
	return true;
}