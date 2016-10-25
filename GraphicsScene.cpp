#include "GraphicsScene.h"
 
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
	sprite->setAnchorPoint(Vec2(0.5,0.5));
	sprite->setPosition(0, 0);
	this->addChild(sprite, 0);
	return true;
}