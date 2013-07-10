/* Miner: config.h
 * Copyright (C) 2012-2013 Sebastian Szymak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined(LOCK_MINER_CONFIG_H)
#define LOCK_MINER_CONFIG_H

class Config {
        public:
                Config();
                virtual ~Config();

                int glWidth() const;
                int glHeight() const;

                unsigned int glMode() const;

        private:
                int m_glWidth;
                int m_glHeight;

                unsigned int m_glMode;

                Config(Config const&); // do not implement
                Config operator=(Config const&); // do not implement
}; // class Config

#endif //LOCK_MINER_CONFIG_H
