#ifndef __SYNCOBJ_H__
#define __SYNCOBJ_H__

#include <windows.h>
#include <stdio.h>

#pragma region("Critical Section Class")
class CritSection  
{
public:
	CritSection() 
	{ 
		memset(&m_cs, 0, sizeof(m_cs)); 
		::InitializeCriticalSection(&m_cs); 
		IsLocked = false;
	}
	virtual ~CritSection() { ::DeleteCriticalSection(&m_cs); }
	
	void Lock()  
	{ 
		::EnterCriticalSection((LPCRITICAL_SECTION)&m_cs); 
		IsLocked = true; 
	}
	void Unlock()  
	{ 
		::LeaveCriticalSection((LPCRITICAL_SECTION)&m_cs); 
		IsLocked = false; 
	}	

	bool IsLocked;

private:
	CRITICAL_SECTION m_cs;
};
#pragma endregion

#pragma region("Automatic Critical Section class")
class AutoCritSection {
	/*
		This class is extremely useful to wrap your critical-section code in this manner:

		"Without":
			CritSection CS;
			...
			CS.Lock();
			<critical section code here>
			CS.Unlock();
			...
			
		"With":
			CritSection CS;
			...
			{
				AutoCritSection acl(&CS);
				<critical section code here>
			}
			...
	*/
	CritSection * h;
public:
	AutoCritSection(CritSection * handle) {
		h = handle;
		if (!h) {
			printf("A valid pointer should be passed");
			exit (1);
		}
		h->Lock();
	}
	AutoCritSection(CritSection & handle) {
		h = &handle;
		if (!h) {
			printf("A valid pointer should be passed");
			exit (1);
		}
		h->Lock();
	}
	~AutoCritSection() {
		h->Unlock();
	}
};
#pragma endregion
#define AUTO_CRIT_SECTION(a) AutoCritSection _______acl__(a)

#endif
