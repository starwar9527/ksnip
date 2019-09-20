/*
 * Copyright (C) 2019 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "WinKeyHandler.h"

WinKeyHandler::~WinKeyHandler()
{
    UnregisterHotKey(nullptr, 1);
}

bool WinKeyHandler::registerKey(const QKeySequence &keySequence)
{
	auto keyCodeCombo = mKeyCodeMapper.map(keySequence);
//    return RegisterHotKey(nullptr, 1, MOD_ALT | MOD_CONTROL | 0x4000, 0x4B);  //ALT + 0x2B is 'K' (In future VK_SNAPSHOT)
    return RegisterHotKey(nullptr, 1, keyCodeCombo.modifier, keyCodeCombo.key);  //ALT + 0x2B is 'K' (In future VK_SNAPSHOT)
}

bool WinKeyHandler::isKeyPressed(void* message)
{
    auto msg = static_cast<MSG*>(message);
    return msg->message == WM_HOTKEY;
}
