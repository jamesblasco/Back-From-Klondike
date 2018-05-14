
#ifndef FRAMETIMER_H___
#define FRAMETIMER_H___


/*!
*	\brief	This function initialises the frame timer and should be called once
*			In your initialisation code.
*/
void  InitFrameTimer();

/*!
*	\brief	This function updates the frametimer.
*/
void  SortFrameTimer();

/*!
*	\brief	This functon will return access to the time taken for the last frame.
*			This is also bound into LUA if you do not specify -DNO_LUA in the compile
*			options
*/
float FrameTime();

#endif


