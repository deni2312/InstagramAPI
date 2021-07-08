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

    class LUser {
        public:
        LUser() = default;
        virtual ~LUser() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> username;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<std::string> profile_pic_id;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;
        std::shared_ptr<bool> has_anonymous_profile_picture;
        std::shared_ptr<std::vector<nlohmann::json>> account_badges;
        std::shared_ptr<int64_t> latest_reel_media;
        std::shared_ptr<std::vector<nlohmann::json>> story_reel_media_ids;
        std::shared_ptr<bool> is_favorite;

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

        std::shared_ptr<std::string> get_profile_pic_id() const { return profile_pic_id; }
        void set_profile_pic_id(std::shared_ptr<std::string> value) { this->profile_pic_id = value; }

        std::shared_ptr<bool> get_is_verified() const { return is_verified; }
        void set_is_verified(std::shared_ptr<bool> value) { this->is_verified = value; }

        std::shared_ptr<int64_t> get_follow_friction_type() const { return follow_friction_type; }
        void set_follow_friction_type(std::shared_ptr<int64_t> value) { this->follow_friction_type = value; }

        std::shared_ptr<bool> get_has_anonymous_profile_picture() const { return has_anonymous_profile_picture; }
        void set_has_anonymous_profile_picture(std::shared_ptr<bool> value) { this->has_anonymous_profile_picture = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_account_badges() const { return account_badges; }
        void set_account_badges(std::shared_ptr<std::vector<nlohmann::json>> value) { this->account_badges = value; }

        std::shared_ptr<int64_t> get_latest_reel_media() const { return latest_reel_media; }
        void set_latest_reel_media(std::shared_ptr<int64_t> value) { this->latest_reel_media = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_story_reel_media_ids() const { return story_reel_media_ids; }
        void set_story_reel_media_ids(std::shared_ptr<std::vector<nlohmann::json>> value) { this->story_reel_media_ids = value; }

        std::shared_ptr<bool> get_is_favorite() const { return is_favorite; }
        void set_is_favorite(std::shared_ptr<bool> value) { this->is_favorite = value; }
    };

    class UserListRequest {
        public:
        UserListRequest() = default;
        virtual ~UserListRequest() = default;

        private:
        nlohmann::json sections;
        nlohmann::json global_blacklist_sample;
        std::shared_ptr<std::vector<LUser>> users;
        std::shared_ptr<bool> big_list;
        std::shared_ptr<int64_t> next_max_id;
        std::shared_ptr<int64_t> page_size;
        std::shared_ptr<std::string> status;

        public:
        const nlohmann::json & get_sections() const { return sections; }
        nlohmann::json & get_mutable_sections() { return sections; }
        void set_sections(const nlohmann::json & value) { this->sections = value; }

        const nlohmann::json & get_global_blacklist_sample() const { return global_blacklist_sample; }
        nlohmann::json & get_mutable_global_blacklist_sample() { return global_blacklist_sample; }
        void set_global_blacklist_sample(const nlohmann::json & value) { this->global_blacklist_sample = value; }

        std::shared_ptr<std::vector<LUser>> get_users() const { return users; }
        void set_users(std::shared_ptr<std::vector<LUser>> value) { this->users = value; }

        std::shared_ptr<bool> get_big_list() const { return big_list; }
        void set_big_list(std::shared_ptr<bool> value) { this->big_list = value; }

        std::shared_ptr<int64_t> get_next_max_id() const { return next_max_id; }
        void set_next_max_id(std::shared_ptr<int64_t> value) { this->next_max_id = value; }

        std::shared_ptr<int64_t> get_page_size() const { return page_size; }
        void set_page_size(std::shared_ptr<int64_t> value) { this->page_size = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, IgTypes::LUser & x);
    void to_json(json & j, const IgTypes::LUser & x);

    void from_json(const json & j, IgTypes::UserListRequest & x);
    void to_json(json & j, const IgTypes::UserListRequest & x);

    inline void from_json(const json & j, IgTypes::LUser& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_username(IgTypes::get_optional<std::string>(j, "username"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_profile_pic_id(IgTypes::get_optional<std::string>(j, "profile_pic_id"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
        x.set_has_anonymous_profile_picture(IgTypes::get_optional<bool>(j, "has_anonymous_profile_picture"));
        x.set_account_badges(IgTypes::get_optional<std::vector<json>>(j, "account_badges"));
        x.set_latest_reel_media(IgTypes::get_optional<int64_t>(j, "latest_reel_media"));
        x.set_story_reel_media_ids(IgTypes::get_optional<std::vector<json>>(j, "story_reel_media_ids"));
        x.set_is_favorite(IgTypes::get_optional<bool>(j, "is_favorite"));
    }

    inline void to_json(json & j, const IgTypes::LUser & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["username"] = x.get_username();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["profile_pic_id"] = x.get_profile_pic_id();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
        j["has_anonymous_profile_picture"] = x.get_has_anonymous_profile_picture();
        j["account_badges"] = x.get_account_badges();
        j["latest_reel_media"] = x.get_latest_reel_media();
        j["story_reel_media_ids"] = x.get_story_reel_media_ids();
        j["is_favorite"] = x.get_is_favorite();
    }

    inline void from_json(const json & j, IgTypes::UserListRequest& x) {
        x.set_sections(IgTypes::get_untyped(j, "sections"));
        x.set_global_blacklist_sample(IgTypes::get_untyped(j, "global_blacklist_sample"));
        x.set_users(IgTypes::get_optional<std::vector<IgTypes::LUser>>(j, "users"));
        x.set_big_list(IgTypes::get_optional<bool>(j, "big_list"));
        x.set_next_max_id(IgTypes::get_optional<int64_t>(j, "next_max_id"));
        x.set_page_size(IgTypes::get_optional<int64_t>(j, "page_size"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
    }

    inline void to_json(json & j, const IgTypes::UserListRequest & x) {
        j = json::object();
        j["sections"] = x.get_sections();
        j["global_blacklist_sample"] = x.get_global_blacklist_sample();
        j["users"] = x.get_users();
        j["big_list"] = x.get_big_list();
        j["next_max_id"] = x.get_next_max_id();
        j["page_size"] = x.get_page_size();
        j["status"] = x.get_status();
    }
}
