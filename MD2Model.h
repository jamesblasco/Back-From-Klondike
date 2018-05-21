#ifndef GL_ADVANCED_FIGURE_H
#define GL_ADVANCED_FIGURE_H


#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "MD2File.h"


/// sets the frames per second that the anims occur at
#define MD2_FRAMES_PER_SEC 5

//-----------------------------------------------------------------------	class MD2Model
//
class MD2Model :  MD2 {
public:
	MD2Model();
	~MD2Model();

	/// \brief	releases the current loaded model
	///
	void Release();

	/// \brief	this func loads the specified md2 file
	/// \param	filename	-	name of the model to load
	/// \return	true if OK
	///
	bool Load(const char* filename);

	/// \brief	this function updates the current animation by the specified
	///			amount. 
	/// \param	dt	-	the time increment
	/// 
	void Update(float dt);

	/// \brief	renders the model using triangle strips if it has them,
	///			otherwise it falls back to triangles
	/// 
	void Render() const;

	/// \brief	This funcion sets the current animation to use
	/// \param	idx	-	the index of the anim to play
	/// 
	void SetAnim(unsigned short);

	/// \brief	This function returns the name of the first frame of 
	///			the specified animation, ie "run01"
	/// \param	idx	-	the animation index
	/// \return	the text name or NULL
	///
	const char* GetAnimName(unsigned short) const;

	/// \brief	This function returns the number of animation cycles contained
	///			within the md2 file
	/// \return	num of anims
	/// 
	unsigned short GetNumAnims() const;

	/// \brief	This function returns the total size of the model in bytes
	/// \param	data size in bytes
	/// 
	unsigned int GetDataSize() const;

protected:

	/// holds a reference to an animation within the MD2 file
	struct AnimRef {
		AnimRef() {} /// ctor

		/// copy ctor
		AnimRef(const AnimRef& ref)
			: m_FrameStart(ref.m_FrameStart),
			m_FrameCount(ref.m_FrameCount) {}

		/// first frame in cycle
		unsigned short m_FrameStart;

		/// number of frames in the cycle
		unsigned short m_FrameCount;
	};

	/// the time of the current anim
	float m_AnimTime;

	/// the final vertex coords
	float* m_Verts;

	/// the current ID of the anim running
	unsigned short m_CurrentAnim;

	/// the number of anims in the md2 
	unsigned short m_NumAnims;

	/// quick references for the animation cycles
	std::vector<AnimRef> m_Anims;
};

#endif
