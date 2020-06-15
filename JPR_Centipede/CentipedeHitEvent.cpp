#include "CentipedeHitEvent.h"
#include "GameObjectManager.h"
#include "CollisionMap.h"
#include "ScoreObject.h"
#include "Centipede.h"
#include "StateTypes.h"
#include "GameObjectFactory.h"
#include "GameObjectState.h"
#include "EngineLib.h"
#include "CommandFactory.h"
#include "CommandType.h"
#include "CentipedeManager.h"
#include "PlayerBullet.h"
#include "MushroomManager.h"

CentipedeHitEvent::CentipedeHitEvent(Centipede* context) {

	this->context = context;
	this->gm = GameObjectManager::getInstance();
	this->cm = CollisionMap::getInstance();
	this->scm = ScoreManager::getInstance();

}

CentipedeHitEvent::~CentipedeHitEvent() {

	//cout << "Destroying CentipedeHitEvent..." << endl;

}

inline bool CentipedeHitEvent::containsBullet(vector<GameObject*> objs) {

	for (int i = 0; i < objs.size(); ++i) {

		PlayerBullet* obj = dynamic_cast<PlayerBullet*>(objs[i]);

		if (obj != NULL
			&& this->context->getCollisionBox().intersects(obj->getCollisionBox()) ) {

			return true;

		}

	}

	return false;

}

inline void CentipedeHitEvent::processNext(Centipede& next) {

	next.setStateType(StateType::CentipedeHeadState);
	next.setPrev(NULL);

}

void CentipedeHitEvent::update(float elapsedTime) {

	if ( this->containsBullet( EngineLib::getIntersectsObj(this->context) ) ) {

		MushroomManager* shroomMngr = MushroomManager::getInstance();

		cout << "Centipede got hit" << endl;
		
		shroomMngr->addMushroom( round(this->context->getPosition().x), round(this->context->getPosition().y) );

		if (this->context->getNext() != NULL) {

			this->processNext(*this->context->getNext());

		}

		CentipedeManager* centiMngr = CentipedeManager::getInstance();
		centiMngr->remove(this->context->getId());

		this->scm->increaseScore(100);

	}

}