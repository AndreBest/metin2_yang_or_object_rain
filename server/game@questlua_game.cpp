// look for int game_drop_item(lua_State* L) and compare/replace/add the defines

        int game_drop_item(lua_State* L)
        {
                LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

                DWORD item_vnum = (DWORD) lua_tonumber(L, 1);
                int count = (int) lua_tonumber(L, 2);
                int x = ch->GetX();
                int y = ch->GetY();
#ifdef __LUA_RADIUS_EXTEND__
                int radius = lua_isnumber(L, 3) ? (int) lua_tonumber(L, 3) : 200;
                if (radius < 1)
                        radius = 1;
#endif

                LPITEM item = ITEM_MANAGER::instance().CreateItem(item_vnum, count);

                if (!item)
                {
                        quest_err("cannot create item vnum %d count %d", item_vnum, count);
                        return 0;
                }

                PIXEL_POSITION pos;
#ifdef __LUA_RADIUS_EXTEND__
                pos.x = x + Random::get(-radius, radius);
                pos.y = y + Random::get(-radius, radius);
#else
                pos.x = x + Random::get(-200, 200);
                pos.y = y + Random::get(-200, 200);
#endif

                item->AddToGround(ch->GetMapIndex(), pos);
                item->StartDestroyEvent();

                return 0;
        }
