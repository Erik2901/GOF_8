#pragma once
#include <iostream>
#include "DynamicObject.h"

class Tree;

class TreeState {
public:
	TreeState();
	~TreeState();
	virtual void Grow(uint16_t DeltaTime, Tree*) = 0;
	virtual void Draw(double x, double y) const = 0;
};

class Tree : public DynamicObject
{
private:
	TreeState* state;
public:
	Tree();
	Tree(TreeState* state1);
	~Tree();
	virtual void Move(uint16_t DeltaTime) override;
	void Draw() const override;
	void SetState(TreeState* s);
};

class SmallTree : public TreeState
{
public:
	void Draw(double x, double y) const override;
	void Grow(uint16_t DeltaTime, Tree* pTree) override;
};

class MiddleTree : public TreeState
{
public:
	void Draw(double x, double y) const override;
	void Grow(uint16_t DeltaTime, Tree* pTree) override;
};

class BigTree : public TreeState
{
public:
	void Draw(double x, double y) const override;
	void Grow(uint16_t DeltaTime, Tree* pTree) override;
};