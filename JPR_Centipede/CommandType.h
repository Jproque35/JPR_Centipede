#ifndef COMMANDTYPE_H
#define COMMANDTYPE_H
#pragma once

enum class CommandType {
	Unknown,
	Empty,
	Generic,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Activate,
	Deactivate,
	SetPosition,
	ShootBullet
};

#endif
