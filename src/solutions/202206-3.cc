#include <bits/stdc++.h>
using namespace std;
class Role {
 public:
  bool operator< (Role role) const {
    return this->name_ < role.name_;
  }
  string name_;
  vector<string> actions_;
  vector<string> resource_categorys_;
  vector<string> resources_;
};
class User {
 public:
  bool operator< (User user) const {
    return this->user_ < user.user_;
  }
  string type_;
  // 这里的 user_ 可以是用户名, 也可以是用户组名
  string user_;
};
class RoleMap {
 public:
  string name_;
  vector<User> users_;
};
class Action {
 public:
  string user_;
  vector<string> user_group_belongs_;
  string action_;
  string resource_catagory;
  string resource;
};
vector<Role> roles;
vector<RoleMap> role_maps;
// 待授权 authorization 行为
vector<Action> actions_to_auth;
int main() {
  int ni, mi, qi;
  cin >> ni >> mi >> qi;
  roles.resize(ni);
  for (auto &role:roles) {
    cin >> role.name_;
    int nv, no, nn;
    cin >> nv;
    role.actions_.resize(nv);
    for (auto &action:role.actions_) {
      cin >> action;
    }
    sort(role.actions_.begin(), role.actions_.end());
    cin >> no;
    role.resource_categorys_.resize(no);
    for (auto &resource_category:role.resource_categorys_) {
      cin >> resource_category;
    }
    sort(role.resource_categorys_.begin(), role.resource_categorys_.end());
    cin >> nn;
    role.resources_.resize(nn);
    for (auto &resource:role.resources_) {
      cin >> resource;
    }
    sort(role.resources_.begin(), role.resources_.end());
  }
  sort(roles.begin(), roles.end(), [](Role a, Role b){
    return a.name_ < b.name_;
  });
  role_maps.resize(mi);
  for (auto &role_map:role_maps) {
    cin >> role_map.name_;
    int ns;
    cin >> ns;
    role_map.users_.resize(ns);
    for (auto &user_group:role_map.users_) {
      cin >> user_group.type_;
      cin >> user_group.user_;
    }
    sort(role_map.users_.begin(), role_map.users_.end(), [](const User& a, const User& b){
      // users_ 是用户组数组, user_ 是用户组名, 把单个人看成用户组
      return a.user_ < b.user_;
    });
  }
  actions_to_auth.resize(qi);
  for (auto &action:actions_to_auth) {
    cin >> action.user_;
    int i;
    cin >> i;
    action.user_group_belongs_.resize(i);
    for (auto &user_group:action.user_group_belongs_) {
      cin >> user_group;
    }
    action.user_group_belongs_.push_back(action.user_);
    cin >> action.action_;
    cin >> action.resource_catagory;
    cin >> action.resource;

    vector<Role*> user_roles;
    for (auto &user_group:action.user_group_belongs_){
      for (auto &role_map:role_maps) {
        if (binary_search(role_map.users_.begin(), role_map.users_.end(), User{"", user_group})) {
          auto it = lower_bound(roles.begin(), roles.end(), 
            Role{role_map.name_});
          user_roles.push_back(&(*it));
        }
      }
      for (auto &role:user_roles) {
        // 找不到动作就 continue
        if (not binary_search(role->actions_.begin(), role->actions_.end(), "*") and 
            not binary_search(role->actions_.begin(), role->actions_.end(), action.action_)) {
          continue;
        }
        // 找不到资源目录就 continue
        if (not binary_search(role->resource_categorys_.begin(), role->resource_categorys_.end(), "*") and
            not binary_search(role->resource_categorys_.begin(), role->resource_categorys_.end(), action.resource_catagory)) {
          continue;
        }
        // 找不到资源就 continue
        if (not role->resources_.empty() and not binary_search(role->resources_.begin(), role->resources_.end(), action.resource)) {
          continue;
        }

        cout << 1 << endl;
        goto authrized;
      }
    }
    cout << 0 << endl;
    authrized:;
  }
}
/*
cmake ../;make;echo -e "1 2 3\nop 1 open 1 door 1 room302\nop 1 g sre\nop 1 u xiaop\nxiaoc 2 sre ops open door room302\nxiaop 1 ops open door room501\nxiaoc 2 sre ops remove door room302\n"|./Basic-algorithm-exercise
1 2 3
op 1 open 1 door 1 room302
op 1 g sre
op 1 u xiaop
xiaoc 2 sre ops open door room302
xiaop 1 ops open door room501
xiaoc 2 sre ops remove door room302

1 1 0
*/