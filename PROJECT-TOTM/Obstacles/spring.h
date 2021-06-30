#ifndef SPRING_H
#define SPRING_H

#include "..\player.h"
#include "..\asset_holder.h"
class spring
{
public:
	////////////////////////////////////////////////////////////
	/// \brief enum class for spring direction/type
	/// 
	////////////////////////////////////////////////////////////
	enum class spring_dir{DOWN_RIGHT,DOWN_LEFT,UP_LEFT, UP_RIGHT};

	////////////////////////////////////////////////////////////
	/// \brief constructor
	///
	/// \param _position position of spring in units of player size
	/// \param _dir direction for spring created
	/// \param _player_var reference to player object
	/// \param asset_source pointer to asset class to be used
	///
	////////////////////////////////////////////////////////////
	spring(sf::Vector2f _position,spring_dir _dir,player& _player_var, asset_holder* asset_source);

	////////////////////////////////////////////////////////////
	/// \brief destructor
	///
	////////////////////////////////////////////////////////////
	~spring();

	////////////////////////////////////////////////////////////
	/// \brief generic update function
	///
	/// serves as container for all other update function/calls
	///
	/// \param _dt delta time value for which frame rate is adjusted
	///
	////////////////////////////////////////////////////////////
	void update(float dt);

	////////////////////////////////////////////////////////////
	/// \brief generic render function
	///
	/// serves as container for all other render functions/calls.
	///
	/// \param target pointer to window in 
	/// which object is to be rendered
	///
	////////////////////////////////////////////////////////////
	void render(sf::RenderTarget* target);

private:
	////////////////////////////////////////////////////////////
	/// \brief size of spring
	///
	////////////////////////////////////////////////////////////
	float BASE_SIZE;

	////////////////////////////////////////////////////////////
	/// \brief times bounce animation timing
	///
	////////////////////////////////////////////////////////////	
	float timer_bounce;

	////////////////////////////////////////////////////////////
	/// \brief times general animation timing
	///
	////////////////////////////////////////////////////////////
	float timer;

	////////////////////////////////////////////////////////////
	/// \brief scales by how much timer chnages and in
	/// which direction
	///
	////////////////////////////////////////////////////////////
	float anim_flash;

	////////////////////////////////////////////////////////////
	/// \brief indicates whether spring is "active" or not
	///
	////////////////////////////////////////////////////////////
	bool is_active;

	////////////////////////////////////////////////////////////
	/// \brief indicates whether bounce animation is 
	/// playing or not
	///
	////////////////////////////////////////////////////////////
	bool bounce_animation;

	////////////////////////////////////////////////////////////
	/// \brief point used for changing player direction
	///
	////////////////////////////////////////////////////////////
	sf::Vector2f trigger_point;

	////////////////////////////////////////////////////////////
	/// \brief sprite showing spring texture
	///
	////////////////////////////////////////////////////////////
	sf::Sprite spring_sprite;

	////////////////////////////////////////////////////////////
	/// \brief sf::floatrect for sprite
	///
	////////////////////////////////////////////////////////////
	sf::IntRect currentframe;

	////////////////////////////////////////////////////////////
	/// \brief player reference to player object for which
	/// spring works 
	///
	////////////////////////////////////////////////////////////
	player& player_var;

	////////////////////////////////////////////////////////////
	/// \brief asset holder from which textures and files used
	///
	////////////////////////////////////////////////////////////
	asset_holder& m_assets;

	////////////////////////////////////////////////////////////
	/// \brief initializes variables
	///
	////////////////////////////////////////////////////////////
	void initvariables();

	////////////////////////////////////////////////////////////
	/// \brief deals with animations
	///
	////////////////////////////////////////////////////////////
	void animation(float _dt);

	////////////////////////////////////////////////////////////
	/// \brief direction of spring 
	///
	////////////////////////////////////////////////////////////
	spring_dir dir;

	////////////////////////////////////////////////////////////
	/// \brief player movement directions and their 
	/// transformations corresponding to spring direction 
	/// 
	////////////////////////////////////////////////////////////
	std::pair <player::move_dir_no[2],player::move_dir_no[2]> directions;
};
#endif 