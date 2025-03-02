/**
 * ###############################################################################
 *  File: game_loop.h
 *  Project: 2D-RPG-Game
 *  Created Date: Fr 31.January 2025, 7:11:00 pm
 *  Author: lbarwe
 *  -----
 *  Last Modified: Sa 01.March 2025, 7:25:18 pm
 *  Modified By: lbarwe
 *  -----
 *  Copyright (c) 2025 Leon Barwe - lbarwe.business@gmail.com
 * ###############################################################################
 */

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <memory>

#include "ui/window/include/window.h"
#include "gfx/render/include/renderer_manager.h"
#include "gfx/texture/include/texture_manager.h"
#include "kernel/input/include/key_input.h"
#include "entities/characters/include/player_character.h"

namespace kernel
{
    /**
     * @brief GameLoop class for handling the game loop.
     */
    class GameLoop
    {
        public:
            /**
             * @brief Construct new GameLoop object.
             * @param aSDLWindow shared pointer to window object
             * @param aRManager unique pointer to renderer manager object
             * @param aTManager unique pointer to texture manager object
             */
            GameLoop(std::shared_ptr<ui::Window> aSDLWindow, std::unique_ptr<gfx::render::RendererManager> aRManager, std::unique_ptr<gfx::texture::TextureManager> aTManager);

            /**
             * @brief Destroy GameLoop object.
             */
            ~GameLoop();
            
            /**
             * @brief Run the game loop.
             * This function handles events, updates game logic and renders the game.
             */
            void run();

        private:
            /**
             * @brief Render all elements of the game.
             */
            void render();
            
            /**
             * @brief Update game logic.
             */
            void update();
            
            /**
             * @brief Handle events for the game.
             * TODO: This function is not implemented yet.
             */
            void handleEvents();
            
            /**
             * @brief Check for input from the user.
             */
            void checkForInput();
            
            std::shared_ptr<ui::Window> mSDLWindow;                             // shared pointer to window object
            std::unique_ptr<gfx::render::RendererManager> mRManager;            // unique pointer to renderer manager object
            std::unique_ptr<gfx::texture::TextureManager> mTManager;            // texture manager object
            std::shared_ptr<entities::characters::PlayerCharacter> mPlayer;     // player character object
            input::KeyInput mKeyInput;                                          // key input object
    };
}

#endif // GAME_LOOP_H