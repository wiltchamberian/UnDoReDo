#ifndef _UNDO_REDO_H_
#define _UNDO_REDO_H_

#pragma once 
#include <deque>
using namespace std;

/*here I provide a general way to realize an undo redo 
operation for an object whose state changes,the
object should have overrided operator = and 
has a copy constructor*/

template<class _T>
class CommandManager
{
public:
	CommandManager():m_maxUndoTimes(10)
	{}
	~CommandManager()
	{}

private:
	int m_maxUndoTimes;
	deque<_T> m_undoStack;
	deque<_T> m_redoStack;

public:
	void setMaxUndoTimes(int times)
	{
		m_maxUndoTimes=times;
	}

	void push(const _T& object)
	{
		m_redoStack.clear();
		if(m_undoStack.size()>=m_maxUndoTimes)
		{
			m_undoStack.pop_front();
		}
		m_undoStack.push_back(object);
	}

	bool undo(_T& object)
	{
		if(m_undoStack.empty())
		{
			return false;
		}
		object=m_undoStack.back();
		m_redoStack.push_back(ojbect);
		m_undoStack.pop_back();
		return true;
	}

	bool redo(_T& ojbect)
	{
		if(m_redoStack.empty())
		{
			return false;
		}
		object=m_redoStack.back();
		m_undoStack.push_back(object);
		m_redoStack.pop_back();
		return true;
	}
};

#endif