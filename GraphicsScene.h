#ifndef __GRAPHICS_SCENE_H__
#define __GRAPHICS_SCENE_H__
#endif
 
#include "cocos2d.h"

class GraphicsScene : public cocos2d::Layer {
	public:
		static cocos2d::Scene* createScene();
		virtual bool init();
		CREATE_FUNC(GraphicsScene);
};