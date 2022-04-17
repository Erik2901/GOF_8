#include "Tree.h"
#include "MyTools.h"
#include "SBomber.h"

using namespace std;
using namespace MyTools;

TreeState::TreeState() {}

TreeState::~TreeState() = default;

Tree::Tree(){}

Tree::Tree(TreeState* state1) {
	state = state1;
}

Tree::~Tree() { delete state; };

void Tree::Move(uint16_t DeltaTime) {
	state->Grow(DeltaTime, this);
}

void Tree::Draw() const {
	state->Draw(x,y);
}

void Tree::SetState(TreeState* s) {
	state = s;
}

void SmallTree::Draw(double x, double y) const {
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 5);
	cout << "**    **";
	GotoXY(x, y - 4);
	cout << "   **   ";
	GotoXY(x, y - 3);
	cout << "** ** **";
	GotoXY(x, y - 2);
	cout << "   **   ";
	GotoXY(x, y - 1);
	cout << "   **   ";
	GotoXY(x, y);
	cout << "********";
}

void SmallTree::Grow(uint16_t DeltaTime, Tree* pTree) {
	if (static_cast<int>(DeltaTime) >= 3)
	{
		pTree->SetState(new MiddleTree());
	}
}

void MiddleTree::Draw(double x, double y) const {
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y-5);
	cout << "***    ***";
	GotoXY(x, y-4);
	cout << "    **    ";
	GotoXY(x, y-3);
	cout << "*** ** ***";
	GotoXY(x, y-2);
	cout << "    **    ";
	GotoXY(x, y-1);
	cout << "    **    ";
	GotoXY(x, y);
	cout << "**********";
}

void MiddleTree::Grow(uint16_t DeltaTime, Tree* pTree) {
	if (static_cast<int>(DeltaTime) >= 6)
	{
		pTree->SetState(new BigTree());
	}
}

void BigTree::Draw(double x, double y) const {
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 5);
	cout << "****    ****";
	GotoXY(x, y - 4);
	cout << "     **     ";
	GotoXY(x, y - 3);
	cout << "**** ** ****";
	GotoXY(x, y - 2);
	cout << "     **     ";
	GotoXY(x, y - 1);
	cout << "     **     ";
	GotoXY(x, y);
	cout << "************";
}

void BigTree::Grow(uint16_t DeltaTime, Tree* pTree) {

}