#pragma once

#include <nlohmann/json.hpp>

#include <optional>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace IgTypes {
    using nlohmann::json;

    class UserLF {
        public:
        UserLF() = default;
        virtual ~UserLF() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> username;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;
        std::shared_ptr<bool> has_anonymous_profile_picture;
        std::shared_ptr<std::string> reel_auto_archive;
        std::shared_ptr<std::string> allowed_commenter_type;
        std::shared_ptr<std::vector<nlohmann::json>> account_badges;
        std::shared_ptr<double> fbid_v2;
        std::shared_ptr<int64_t> latest_reel_media;
        std::shared_ptr<std::string> profile_pic_id;

        public:
        std::shared_ptr<int64_t> get_pk() const { return pk; }
        void set_pk(std::shared_ptr<int64_t> value) { this->pk = value; }

        std::shared_ptr<std::string> get_username() const { return username; }
        void set_username(std::shared_ptr<std::string> value) { this->username = value; }

        std::shared_ptr<std::string> get_full_name() const { return full_name; }
        void set_full_name(std::shared_ptr<std::string> value) { this->full_name = value; }

        std::shared_ptr<bool> get_is_private() const { return is_private; }
        void set_is_private(std::shared_ptr<bool> value) { this->is_private = value; }

        std::shared_ptr<std::string> get_profile_pic_url() const { return profile_pic_url; }
        void set_profile_pic_url(std::shared_ptr<std::string> value) { this->profile_pic_url = value; }

        std::shared_ptr<bool> get_is_verified() const { return is_verified; }
        void set_is_verified(std::shared_ptr<bool> value) { this->is_verified = value; }

        std::shared_ptr<int64_t> get_follow_friction_type() const { return follow_friction_type; }
        void set_follow_friction_type(std::shared_ptr<int64_t> value) { this->follow_friction_type = value; }

        std::shared_ptr<bool> get_has_anonymous_profile_picture() const { return has_anonymous_profile_picture; }
        void set_has_anonymous_profile_picture(std::shared_ptr<bool> value) { this->has_anonymous_profile_picture = value; }

        std::shared_ptr<std::string> get_reel_auto_archive() const { return reel_auto_archive; }
        void set_reel_auto_archive(std::shared_ptr<std::string> value) { this->reel_auto_archive = value; }

        std::shared_ptr<std::string> get_allowed_commenter_type() const { return allowed_commenter_type; }
        void set_allowed_commenter_type(std::shared_ptr<std::string> value) { this->allowed_commenter_type = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_account_badges() const { return account_badges; }
        void set_account_badges(std::shared_ptr<std::vector<nlohmann::json>> value) { this->account_badges = value; }

        std::shared_ptr<double> get_fbid_v2() const { return fbid_v2; }
        void set_fbid_v2(std::shared_ptr<double> value) { this->fbid_v2 = value; }

        std::shared_ptr<int64_t> get_latest_reel_media() const { return latest_reel_media; }
        void set_latest_reel_media(std::shared_ptr<int64_t> value) { this->latest_reel_media = value; }

        std::shared_ptr<std::string> get_profile_pic_id() const { return profile_pic_id; }
        void set_profile_pic_id(std::shared_ptr<std::string> value) { this->profile_pic_id = value; }
    };

    class UserListRequestFollow {
        public:
        UserListRequestFollow() = default;
        virtual ~UserListRequestFollow() = default;

        private:
        std::shared_ptr<std::vector<UserLF>> users;
        std::shared_ptr<bool> big_list;
        std::shared_ptr<int64_t> page_size;
        std::shared_ptr<std::string> next_max_id;
        std::shared_ptr<std::string> status;

        public:
        std::shared_ptr<std::vector<UserLF>> get_users() const { return users; }
        void set_users(std::shared_ptr<std::vector<UserLF>> value) { this->users = value; }

        std::shared_ptr<bool> get_big_list() const { return big_list; }
        void set_big_list(std::shared_ptr<bool> value) { this->big_list = value; }

        std::shared_ptr<int64_t> get_page_size() const { return page_size; }
        void set_page_size(std::shared_ptr<int64_t> value) { this->page_size = value; }

        std::shared_ptr<std::string> get_next_max_id() const { return next_max_id; }
        void set_next_max_id(std::shared_ptr<std::string> value) { this->next_max_id = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, IgTypes::UserLF & x);
    void to_json(json & j, const IgTypes::UserLF & x);

    void from_json(const json & j, IgTypes::UserListRequestFollow & x);
    void to_json(json & j, const IgTypes::UserListRequestFollow & x);

    inline void from_json(const json & j, IgTypes::UserLF& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_username(IgTypes::get_optional<std::string>(j, "username"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
        x.set_has_anonymous_profile_picture(IgTypes::get_optional<bool>(j, "has_anonymous_profile_picture"));
        x.set_reel_auto_archive(IgTypes::get_optional<std::string>(j, "reel_auto_archive"));
        x.set_allowed_commenter_type(IgTypes::get_optional<std::string>(j, "allowed_commenter_type"));
        x.set_account_badges(IgTypes::get_optional<std::vector<json>>(j, "account_badges"));
        x.set_fbid_v2(IgTypes::get_optional<double>(j, "fbid_v2"));
        x.set_latest_reel_media(IgTypes::get_optional<int64_t>(j, "latest_reel_media"));
        x.set_profile_pic_id(IgTypes::get_optional<std::string>(j, "profile_pic_id"));
    }

    inline void to_json(json & j, const IgTypes::UserLF & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["username"] = x.get_username();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
        j["has_anonymous_profile_picture"] = x.get_has_anonymous_profile_picture();
        j["reel_auto_archive"] = x.get_reel_auto_archive();
        j["allowed_commenter_type"] = x.get_allowed_commenter_type();
        j["account_badges"] = x.get_account_badges();
        j["fbid_v2"] = x.get_fbid_v2();
        j["latest_reel_media"] = x.get_latest_reel_media();
        j["profile_pic_id"] = x.get_profile_pic_id();
    }

    inline void from_json(const json & j, IgTypes::UserListRequestFollow& x) {
        x.set_users(IgTypes::get_optional<std::vector<IgTypes::UserLF>>(j, "users"));
        x.set_big_list(IgTypes::get_optional<bool>(j, "big_list"));
        x.set_page_size(IgTypes::get_optional<int64_t>(j, "page_size"));
        x.set_next_max_id(IgTypes::get_optional<std::string>(j, "next_max_id"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
    }

    inline void to_json(json & j, const IgTypes::UserListRequestFollow & x) {
        j = json::object();
        j["users"] = x.get_users();
        j["big_list"] = x.get_big_list();
        j["page_size"] = x.get_page_size();
        j["next_max_id"] = x.get_next_max_id();
        j["status"] = x.get_status();
    }
}
