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

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    class HdProfilePic {
        public:
        HdProfilePic() = default;
        virtual ~HdProfilePic() = default;

        private:
        std::shared_ptr<int64_t> width;
        std::shared_ptr<int64_t> height;
        std::shared_ptr<std::string> url;

        public:
        std::shared_ptr<int64_t> get_width() const { return width; }
        void set_width(std::shared_ptr<int64_t> value) { this->width = value; }

        std::shared_ptr<int64_t> get_height() const { return height; }
        void set_height(std::shared_ptr<int64_t> value) { this->height = value; }

        std::shared_ptr<std::string> get_url() const { return url; }
        void set_url(std::shared_ptr<std::string> value) { this->url = value; }
    };

    class User {
        public:
        User() = default;
        virtual ~User() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> username;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;
        std::shared_ptr<bool> has_anonymous_profile_picture;
        std::shared_ptr<int64_t> media_count;
        std::shared_ptr<int64_t> geo_media_count;
        std::shared_ptr<int64_t> follower_count;
        std::shared_ptr<int64_t> following_count;
        std::shared_ptr<int64_t> following_tag_count;
        std::shared_ptr<std::string> biography;
        std::shared_ptr<std::string> external_url;
        std::shared_ptr<int64_t> total_igtv_videos;
        std::shared_ptr<int64_t> usertags_count;
        std::shared_ptr<bool> is_favorite;
        std::shared_ptr<bool> has_chaining;
        std::shared_ptr<std::vector<HdProfilePic>> hd_profile_pic_versions;
        std::shared_ptr<HdProfilePic> hd_profile_pic_url_info;
        std::shared_ptr<int64_t> mutual_followers_count;
        std::shared_ptr<bool> has_guides;
        std::shared_ptr<bool> is_eligible_for_smb_support_flow;
        nlohmann::json smb_support_partner;
        std::shared_ptr<std::string> direct_messaging;
        std::shared_ptr<std::string> fb_page_call_to_action_id;
        std::shared_ptr<std::string> address_street;
        std::shared_ptr<std::string> business_contact_method;
        std::shared_ptr<std::string> category;
        std::shared_ptr<int64_t> city_id;
        std::shared_ptr<std::string> city_name;
        std::shared_ptr<std::string> contact_phone_number;
        std::shared_ptr<bool> is_call_to_action_enabled;
        std::shared_ptr<int64_t> latitude;
        std::shared_ptr<int64_t> longitude;
        std::shared_ptr<std::string> public_email;
        std::shared_ptr<std::string> public_phone_country_code;
        std::shared_ptr<std::string> public_phone_number;
        std::shared_ptr<std::string> zip;
        std::shared_ptr<std::string> instagram_location_id;
        std::shared_ptr<bool> is_business;
        std::shared_ptr<int64_t> account_type;
        std::shared_ptr<int64_t> professional_conversion_suggested_account_type;
        std::shared_ptr<bool> can_hide_category;
        std::shared_ptr<bool> can_hide_public_contacts;
        std::shared_ptr<bool> should_show_category;
        std::shared_ptr<bool> should_show_public_contacts;
        std::shared_ptr<std::vector<nlohmann::json>> account_badges;

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

        std::shared_ptr<int64_t> get_media_count() const { return media_count; }
        void set_media_count(std::shared_ptr<int64_t> value) { this->media_count = value; }

        std::shared_ptr<int64_t> get_geo_media_count() const { return geo_media_count; }
        void set_geo_media_count(std::shared_ptr<int64_t> value) { this->geo_media_count = value; }

        std::shared_ptr<int64_t> get_follower_count() const { return follower_count; }
        void set_follower_count(std::shared_ptr<int64_t> value) { this->follower_count = value; }

        std::shared_ptr<int64_t> get_following_count() const { return following_count; }
        void set_following_count(std::shared_ptr<int64_t> value) { this->following_count = value; }

        std::shared_ptr<int64_t> get_following_tag_count() const { return following_tag_count; }
        void set_following_tag_count(std::shared_ptr<int64_t> value) { this->following_tag_count = value; }

        std::shared_ptr<std::string> get_biography() const { return biography; }
        void set_biography(std::shared_ptr<std::string> value) { this->biography = value; }

        std::shared_ptr<std::string> get_external_url() const { return external_url; }
        void set_external_url(std::shared_ptr<std::string> value) { this->external_url = value; }

        std::shared_ptr<int64_t> get_total_igtv_videos() const { return total_igtv_videos; }
        void set_total_igtv_videos(std::shared_ptr<int64_t> value) { this->total_igtv_videos = value; }

        std::shared_ptr<int64_t> get_usertags_count() const { return usertags_count; }
        void set_usertags_count(std::shared_ptr<int64_t> value) { this->usertags_count = value; }

        std::shared_ptr<bool> get_is_favorite() const { return is_favorite; }
        void set_is_favorite(std::shared_ptr<bool> value) { this->is_favorite = value; }

        std::shared_ptr<bool> get_has_chaining() const { return has_chaining; }
        void set_has_chaining(std::shared_ptr<bool> value) { this->has_chaining = value; }

        std::shared_ptr<std::vector<HdProfilePic>> get_hd_profile_pic_versions() const { return hd_profile_pic_versions; }
        void set_hd_profile_pic_versions(std::shared_ptr<std::vector<HdProfilePic>> value) { this->hd_profile_pic_versions = value; }

        std::shared_ptr<HdProfilePic> get_hd_profile_pic_url_info() const { return hd_profile_pic_url_info; }
        void set_hd_profile_pic_url_info(std::shared_ptr<HdProfilePic> value) { this->hd_profile_pic_url_info = value; }

        std::shared_ptr<int64_t> get_mutual_followers_count() const { return mutual_followers_count; }
        void set_mutual_followers_count(std::shared_ptr<int64_t> value) { this->mutual_followers_count = value; }

        std::shared_ptr<bool> get_has_guides() const { return has_guides; }
        void set_has_guides(std::shared_ptr<bool> value) { this->has_guides = value; }

        std::shared_ptr<bool> get_is_eligible_for_smb_support_flow() const { return is_eligible_for_smb_support_flow; }
        void set_is_eligible_for_smb_support_flow(std::shared_ptr<bool> value) { this->is_eligible_for_smb_support_flow = value; }

        const nlohmann::json & get_smb_support_partner() const { return smb_support_partner; }
        nlohmann::json & get_mutable_smb_support_partner() { return smb_support_partner; }
        void set_smb_support_partner(const nlohmann::json & value) { this->smb_support_partner = value; }

        std::shared_ptr<std::string> get_direct_messaging() const { return direct_messaging; }
        void set_direct_messaging(std::shared_ptr<std::string> value) { this->direct_messaging = value; }

        std::shared_ptr<std::string> get_fb_page_call_to_action_id() const { return fb_page_call_to_action_id; }
        void set_fb_page_call_to_action_id(std::shared_ptr<std::string> value) { this->fb_page_call_to_action_id = value; }

        std::shared_ptr<std::string> get_address_street() const { return address_street; }
        void set_address_street(std::shared_ptr<std::string> value) { this->address_street = value; }

        std::shared_ptr<std::string> get_business_contact_method() const { return business_contact_method; }
        void set_business_contact_method(std::shared_ptr<std::string> value) { this->business_contact_method = value; }

        std::shared_ptr<std::string> get_category() const { return category; }
        void set_category(std::shared_ptr<std::string> value) { this->category = value; }

        std::shared_ptr<int64_t> get_city_id() const { return city_id; }
        void set_city_id(std::shared_ptr<int64_t> value) { this->city_id = value; }

        std::shared_ptr<std::string> get_city_name() const { return city_name; }
        void set_city_name(std::shared_ptr<std::string> value) { this->city_name = value; }

        std::shared_ptr<std::string> get_contact_phone_number() const { return contact_phone_number; }
        void set_contact_phone_number(std::shared_ptr<std::string> value) { this->contact_phone_number = value; }

        std::shared_ptr<bool> get_is_call_to_action_enabled() const { return is_call_to_action_enabled; }
        void set_is_call_to_action_enabled(std::shared_ptr<bool> value) { this->is_call_to_action_enabled = value; }

        std::shared_ptr<int64_t> get_latitude() const { return latitude; }
        void set_latitude(std::shared_ptr<int64_t> value) { this->latitude = value; }

        std::shared_ptr<int64_t> get_longitude() const { return longitude; }
        void set_longitude(std::shared_ptr<int64_t> value) { this->longitude = value; }

        std::shared_ptr<std::string> get_public_email() const { return public_email; }
        void set_public_email(std::shared_ptr<std::string> value) { this->public_email = value; }

        std::shared_ptr<std::string> get_public_phone_country_code() const { return public_phone_country_code; }
        void set_public_phone_country_code(std::shared_ptr<std::string> value) { this->public_phone_country_code = value; }

        std::shared_ptr<std::string> get_public_phone_number() const { return public_phone_number; }
        void set_public_phone_number(std::shared_ptr<std::string> value) { this->public_phone_number = value; }

        std::shared_ptr<std::string> get_zip() const { return zip; }
        void set_zip(std::shared_ptr<std::string> value) { this->zip = value; }

        std::shared_ptr<std::string> get_instagram_location_id() const { return instagram_location_id; }
        void set_instagram_location_id(std::shared_ptr<std::string> value) { this->instagram_location_id = value; }

        std::shared_ptr<bool> get_is_business() const { return is_business; }
        void set_is_business(std::shared_ptr<bool> value) { this->is_business = value; }

        std::shared_ptr<int64_t> get_account_type() const { return account_type; }
        void set_account_type(std::shared_ptr<int64_t> value) { this->account_type = value; }

        std::shared_ptr<int64_t> get_professional_conversion_suggested_account_type() const { return professional_conversion_suggested_account_type; }
        void set_professional_conversion_suggested_account_type(std::shared_ptr<int64_t> value) { this->professional_conversion_suggested_account_type = value; }

        std::shared_ptr<bool> get_can_hide_category() const { return can_hide_category; }
        void set_can_hide_category(std::shared_ptr<bool> value) { this->can_hide_category = value; }

        std::shared_ptr<bool> get_can_hide_public_contacts() const { return can_hide_public_contacts; }
        void set_can_hide_public_contacts(std::shared_ptr<bool> value) { this->can_hide_public_contacts = value; }

        std::shared_ptr<bool> get_should_show_category() const { return should_show_category; }
        void set_should_show_category(std::shared_ptr<bool> value) { this->should_show_category = value; }

        std::shared_ptr<bool> get_should_show_public_contacts() const { return should_show_public_contacts; }
        void set_should_show_public_contacts(std::shared_ptr<bool> value) { this->should_show_public_contacts = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_account_badges() const { return account_badges; }
        void set_account_badges(std::shared_ptr<std::vector<nlohmann::json>> value) { this->account_badges = value; }
    };

    class UserRequest {
        public:
        UserRequest() = default;
        virtual ~UserRequest() = default;

        private:
        std::shared_ptr<User> user;
        std::shared_ptr<std::string> status;

        public:
        std::shared_ptr<User> get_user() const { return user; }
        void set_user(std::shared_ptr<User> value) { this->user = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, IgTypes::HdProfilePic & x);
    void to_json(json & j, const IgTypes::HdProfilePic & x);

    void from_json(const json & j, IgTypes::User & x);
    void to_json(json & j, const IgTypes::User & x);

    void from_json(const json & j, IgTypes::UserRequest & x);
    void to_json(json & j, const IgTypes::UserRequest & x);

    inline void from_json(const json & j, IgTypes::HdProfilePic& x) {
        x.set_width(IgTypes::get_optional<int64_t>(j, "width"));
        x.set_height(IgTypes::get_optional<int64_t>(j, "height"));
        x.set_url(IgTypes::get_optional<std::string>(j, "url"));
    }

    inline void to_json(json & j, const IgTypes::HdProfilePic & x) {
        j = json::object();
        j["width"] = x.get_width();
        j["height"] = x.get_height();
        j["url"] = x.get_url();
    }

    inline void from_json(const json & j, IgTypes::User& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_username(IgTypes::get_optional<std::string>(j, "username"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
        x.set_has_anonymous_profile_picture(IgTypes::get_optional<bool>(j, "has_anonymous_profile_picture"));
        x.set_media_count(IgTypes::get_optional<int64_t>(j, "media_count"));
        x.set_geo_media_count(IgTypes::get_optional<int64_t>(j, "geo_media_count"));
        x.set_follower_count(IgTypes::get_optional<int64_t>(j, "follower_count"));
        x.set_following_count(IgTypes::get_optional<int64_t>(j, "following_count"));
        x.set_following_tag_count(IgTypes::get_optional<int64_t>(j, "following_tag_count"));
        x.set_biography(IgTypes::get_optional<std::string>(j, "biography"));
        x.set_external_url(IgTypes::get_optional<std::string>(j, "external_url"));
        x.set_total_igtv_videos(IgTypes::get_optional<int64_t>(j, "total_igtv_videos"));
        x.set_usertags_count(IgTypes::get_optional<int64_t>(j, "usertags_count"));
        x.set_is_favorite(IgTypes::get_optional<bool>(j, "is_favorite"));
        x.set_has_chaining(IgTypes::get_optional<bool>(j, "has_chaining"));
        x.set_hd_profile_pic_versions(IgTypes::get_optional<std::vector<IgTypes::HdProfilePic>>(j, "hd_profile_pic_versions"));
        x.set_hd_profile_pic_url_info(IgTypes::get_optional<IgTypes::HdProfilePic>(j, "hd_profile_pic_url_info"));
        x.set_mutual_followers_count(IgTypes::get_optional<int64_t>(j, "mutual_followers_count"));
        x.set_has_guides(IgTypes::get_optional<bool>(j, "has_guides"));
        x.set_is_eligible_for_smb_support_flow(IgTypes::get_optional<bool>(j, "is_eligible_for_smb_support_flow"));
        x.set_smb_support_partner(IgTypes::get_untyped(j, "smb_support_partner"));
        x.set_direct_messaging(IgTypes::get_optional<std::string>(j, "direct_messaging"));
        x.set_fb_page_call_to_action_id(IgTypes::get_optional<std::string>(j, "fb_page_call_to_action_id"));
        x.set_address_street(IgTypes::get_optional<std::string>(j, "address_street"));
        x.set_business_contact_method(IgTypes::get_optional<std::string>(j, "business_contact_method"));
        x.set_category(IgTypes::get_optional<std::string>(j, "category"));
        x.set_city_id(IgTypes::get_optional<int64_t>(j, "city_id"));
        x.set_city_name(IgTypes::get_optional<std::string>(j, "city_name"));
        x.set_contact_phone_number(IgTypes::get_optional<std::string>(j, "contact_phone_number"));
        x.set_is_call_to_action_enabled(IgTypes::get_optional<bool>(j, "is_call_to_action_enabled"));
        x.set_latitude(IgTypes::get_optional<int64_t>(j, "latitude"));
        x.set_longitude(IgTypes::get_optional<int64_t>(j, "longitude"));
        x.set_public_email(IgTypes::get_optional<std::string>(j, "public_email"));
        x.set_public_phone_country_code(IgTypes::get_optional<std::string>(j, "public_phone_country_code"));
        x.set_public_phone_number(IgTypes::get_optional<std::string>(j, "public_phone_number"));
        x.set_zip(IgTypes::get_optional<std::string>(j, "zip"));
        x.set_instagram_location_id(IgTypes::get_optional<std::string>(j, "instagram_location_id"));
        x.set_is_business(IgTypes::get_optional<bool>(j, "is_business"));
        x.set_account_type(IgTypes::get_optional<int64_t>(j, "account_type"));
        x.set_professional_conversion_suggested_account_type(IgTypes::get_optional<int64_t>(j, "professional_conversion_suggested_account_type"));
        x.set_can_hide_category(IgTypes::get_optional<bool>(j, "can_hide_category"));
        x.set_can_hide_public_contacts(IgTypes::get_optional<bool>(j, "can_hide_public_contacts"));
        x.set_should_show_category(IgTypes::get_optional<bool>(j, "should_show_category"));
        x.set_should_show_public_contacts(IgTypes::get_optional<bool>(j, "should_show_public_contacts"));
        x.set_account_badges(IgTypes::get_optional<std::vector<json>>(j, "account_badges"));
    }

    inline void to_json(json & j, const IgTypes::User & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["username"] = x.get_username();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
        j["has_anonymous_profile_picture"] = x.get_has_anonymous_profile_picture();
        j["media_count"] = x.get_media_count();
        j["geo_media_count"] = x.get_geo_media_count();
        j["follower_count"] = x.get_follower_count();
        j["following_count"] = x.get_following_count();
        j["following_tag_count"] = x.get_following_tag_count();
        j["biography"] = x.get_biography();
        j["external_url"] = x.get_external_url();
        j["total_igtv_videos"] = x.get_total_igtv_videos();
        j["usertags_count"] = x.get_usertags_count();
        j["is_favorite"] = x.get_is_favorite();
        j["has_chaining"] = x.get_has_chaining();
        j["hd_profile_pic_versions"] = x.get_hd_profile_pic_versions();
        j["hd_profile_pic_url_info"] = x.get_hd_profile_pic_url_info();
        j["mutual_followers_count"] = x.get_mutual_followers_count();
        j["has_guides"] = x.get_has_guides();
        j["is_eligible_for_smb_support_flow"] = x.get_is_eligible_for_smb_support_flow();
        j["smb_support_partner"] = x.get_smb_support_partner();
        j["direct_messaging"] = x.get_direct_messaging();
        j["fb_page_call_to_action_id"] = x.get_fb_page_call_to_action_id();
        j["address_street"] = x.get_address_street();
        j["business_contact_method"] = x.get_business_contact_method();
        j["category"] = x.get_category();
        j["city_id"] = x.get_city_id();
        j["city_name"] = x.get_city_name();
        j["contact_phone_number"] = x.get_contact_phone_number();
        j["is_call_to_action_enabled"] = x.get_is_call_to_action_enabled();
        j["latitude"] = x.get_latitude();
        j["longitude"] = x.get_longitude();
        j["public_email"] = x.get_public_email();
        j["public_phone_country_code"] = x.get_public_phone_country_code();
        j["public_phone_number"] = x.get_public_phone_number();
        j["zip"] = x.get_zip();
        j["instagram_location_id"] = x.get_instagram_location_id();
        j["is_business"] = x.get_is_business();
        j["account_type"] = x.get_account_type();
        j["professional_conversion_suggested_account_type"] = x.get_professional_conversion_suggested_account_type();
        j["can_hide_category"] = x.get_can_hide_category();
        j["can_hide_public_contacts"] = x.get_can_hide_public_contacts();
        j["should_show_category"] = x.get_should_show_category();
        j["should_show_public_contacts"] = x.get_should_show_public_contacts();
        j["account_badges"] = x.get_account_badges();
    }

    inline void from_json(const json & j, IgTypes::UserRequest& x) {
        x.set_user(IgTypes::get_optional<IgTypes::User>(j, "user"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
    }

    inline void to_json(json & j, const IgTypes::UserRequest & x) {
        j = json::object();
        j["user"] = x.get_user();
        j["status"] = x.get_status();
    }
}
