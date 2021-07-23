#ifndef GAME_H
#define GAME_H

#include "context.h"
#include "main_menu.h"

////////////////////////////////////////////////////////////
/// \brief game class where game states and running happens
///
/// This class mantains the game stack,window and runs
/// the game loop
///
////////////////////////////////////////////////////////////
class game
{
private:
	////////////////////////////////////////////////////////////
	/// \brief context of the game class
	///
	/// This is a shared ptr variable of context struct
	/// which has all variables needed by states to run properly
	////////////////////////////////////////////////////////////
	std::shared_ptr<context> m_context;

	////////////////////////////////////////////////////////////
	/// \brief initializes fonts
	///
	/// initializes fonts inside m_assets for
	/// use through out game
	////////////////////////////////////////////////////////////
	void InitFonts();

	////////////////////////////////////////////////////////////
	/// \brief initializes textures
	///
	/// initializes textures inside m_assets for
	/// use through out game
	////////////////////////////////////////////////////////////
	void InitTextures();

	////////////////////////////////////////////////////////////
	/// \brief initializes sounds
	///
	/// initializes sounds inside m_assets for
	/// use through out game
	////////////////////////////////////////////////////////////
	void InitSounds();

public:
	////////////////////////////////////////////////////////////
	/// \brief Constructor
	///
	////////////////////////////////////////////////////////////
	game();

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	////////////////////////////////////////////////////////////
	~game();

	////////////////////////////////////////////////////////////
	/// \brief Method to run game loop
	///
	/// This function is used to run the game loop on the state
	/// on top of stack and update statestack.
	/// 
	////////////////////////////////////////////////////////////
	void run();
};

////////////////////////////////////////////////////////////
/// 
/// \class game
///
/// \brief main game loop
///
/// This class stores and runs the main game loop
///
////////////////////////////////////////////////////////////

#endif