#include "HelloWorld.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//sprite = Sprite::create("Car.png");
	//sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	//this->addChild(sprite, 0);

	//this->scheduleUpdate();
	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void {
		/*auto action = cocos2d::MoveBy::create(2, cocos2d::Vec2(-100, 150));
		sprite->runAction(action);*/
		
	//action chain in order
		/*cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
		actions.pushBack(cocos2d::ScaleBy::create(1.5, 1.5));
		actions.pushBack(cocos2d::TintTo::create(1.5, 255, 0, 0));
		actions.pushBack(cocos2d::FadeOut::create(1.5));
		auto sequence = cocos2d::Sequence::create(actions);
		sprite->runAction(sequence);*/

	//multipul action at same time
		/*cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
		actions.pushBack(cocos2d::ScaleBy::create(1.5,2.0));
		actions.pushBack(cocos2d::RotateBy::create(1.5, cocos2d::Vec3(180.5, 75.5, 25.5)));
		actions.pushBack(cocos2d::TintTo::create(1.5, 137, 52, 18));

		auto parallel = cocos2d::Spawn::create(actions);
		sprite->runAction(parallel);*/

	// repeat action 
		/*auto action = cocos2d::MoveBy::create(0.2, cocos2d::Vec2(10, 0));
		auto action2 = cocos2d::ScaleBy::create(2, 1.3);
		auto repeat = cocos2d::Repeat::create(action, 10);
		auto repeatForever = cocos2d::RepeatForever::create(action2);

		sprite->runAction(repeat);
		sprite->runAction(repeatForever);*/

		//cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
		//actions.pushBack(cocos2d::MoveTo::create(0, cocos2d::Vec2(0, 0)));
		//actions.pushBack(cocos2d::DelayTime::create(1));
		//actions.pushBack(cocos2d::Place::create(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY())));
		//actions.pushBack(cocos2d::DelayTime::create(1));
		//actions.pushBack(cocos2d::FlipX::create(true));
		//actions.pushBack(cocos2d::DelayTime::create(1));
		//actions.pushBack(cocos2d::FlipY::create(true));
		//actions.pushBack(cocos2d::DelayTime::create(1));
		//actions.pushBack(cocos2d::Hide::create());
		//actions.pushBack(cocos2d::DelayTime::create(1));
		//actions.pushBack(cocos2d::Show::create());
		//actions.pushBack(cocos2d::DelayTime::create(1));

		//actions.pushBack(cocos2d::CallFunc::create([=]()->void {
		//	//this->setColor(cocos2d::Color3B::RED);
		//	sprite->setTexture("smile.jpg");
		//}));
		//actions.pushBack(cocos2d::DelayTime::create(1));
		//actions.pushBack(cocos2d::RemoveSelf::create(false));

		//auto sequence = cocos2d::Sequence::create(actions);
		//sprite->runAction(sequence);

		/*SpriteBatchNode* spritebatch = SpriteBatchNode::create("cityscene/capguy/walk.png");
		auto Sprite1 = Sprite::createWithSpriteFrameName("0001.png");
		spritebatch->addChild(Sprite1);
		addChild(spritebatch);*/

		SpriteBatchNode* spritebatch = SpriteBatchNode::create("cityscene/capguy/walk.png");
		auto* cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("cityscene/capguy/walk.plist");
		auto sprite = Sprite::createWithSpriteFrameName("0001.png");
		sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
		spritebatch->addChild(sprite);
		addChild(spritebatch);
		this->addChild(sprite, 0);

		Vector<SpriteFrame*> animFrames(8);
		char str[100] = { 0 };
		for (int i = 1; i <= 8; i++) {
			sprintf(str, "000%d.png", i);
			auto* frame = cache->getSpriteFrameByName(str);
			animFrames.pushBack(frame);
		}

		Animation * animation = Animation::createWithSpriteFrames(animFrames, 0.3f);
		sprite->runAction(RepeatForever::create(Animate::create(animation)));
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void HelloWorld::update(float delta) {
	auto position = sprite->getPosition();
	position.x -= 250 * delta;
	if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
		position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
	sprite->setPosition(position);
}