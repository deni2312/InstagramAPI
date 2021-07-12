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

    class Nametag {
        public:
        Nametag() = default;
        virtual ~Nametag() = default;

        private:
        std::shared_ptr<int64_t> mode;
        std::shared_ptr<int64_t> gradient;
        std::shared_ptr<std::string> emoji;
        std::shared_ptr<int64_t> selfie_sticker;

        public:
        std::shared_ptr<int64_t> get_mode() const { return mode; }
        void set_mode(std::shared_ptr<int64_t> value) { this->mode = value; }

        std::shared_ptr<int64_t> get_gradient() const { return gradient; }
        void set_gradient(std::shared_ptr<int64_t> value) { this->gradient = value; }

        std::shared_ptr<std::string> get_emoji() const { return emoji; }
        void set_emoji(std::shared_ptr<std::string> value) { this->emoji = value; }

        std::shared_ptr<int64_t> get_selfie_sticker() const { return selfie_sticker; }
        void set_selfie_sticker(std::shared_ptr<int64_t> value) { this->selfie_sticker = value; }
    };

    class LoggedInUser {
        public:
        LoggedInUser() = default;
        virtual ~LoggedInUser() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> username;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;
        std::shared_ptr<bool> has_anonymous_profile_picture;
        std::shared_ptr<bool> can_boost_post;
        std::shared_ptr<bool> is_business;
        std::shared_ptr<int64_t> account_type;
        std::shared_ptr<int64_t> professional_conversion_suggested_account_type;
        nlohmann::json is_call_to_action_enabled;
        std::shared_ptr<bool> can_see_organic_insights;
        std::shared_ptr<bool> show_insights_terms;
        std::shared_ptr<int64_t> total_igtv_videos;
        std::shared_ptr<std::string> reel_auto_archive;
        std::shared_ptr<bool> has_placed_orders;
        std::shared_ptr<std::string> allowed_commenter_type;
        std::shared_ptr<Nametag> nametag;
        std::shared_ptr<bool> is_using_unified_inbox_for_direct;
        std::shared_ptr<int64_t> biz_user_inbox_state;
        std::shared_ptr<bool> wa_addressable;
        std::shared_ptr<int64_t> wa_eligibility;
        std::shared_ptr<double> interop_messaging_user_fbid;
        std::shared_ptr<bool> can_see_primary_country_in_settings;
        std::shared_ptr<std::vector<nlohmann::json>> account_badges;
        std::shared_ptr<double> fbid_v2;
        std::shared_ptr<bool> allow_contacts_sync;
        std::shared_ptr<std::string> phone_number;

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

        std::shared_ptr<bool> get_can_boost_post() const { return can_boost_post; }
        void set_can_boost_post(std::shared_ptr<bool> value) { this->can_boost_post = value; }

        std::shared_ptr<bool> get_is_business() const { return is_business; }
        void set_is_business(std::shared_ptr<bool> value) { this->is_business = value; }

        std::shared_ptr<int64_t> get_account_type() const { return account_type; }
        void set_account_type(std::shared_ptr<int64_t> value) { this->account_type = value; }

        std::shared_ptr<int64_t> get_professional_conversion_suggested_account_type() const { return professional_conversion_suggested_account_type; }
        void set_professional_conversion_suggested_account_type(std::shared_ptr<int64_t> value) { this->professional_conversion_suggested_account_type = value; }

        const nlohmann::json & get_is_call_to_action_enabled() const { return is_call_to_action_enabled; }
        nlohmann::json & get_mutable_is_call_to_action_enabled() { return is_call_to_action_enabled; }
        void set_is_call_to_action_enabled(const nlohmann::json & value) { this->is_call_to_action_enabled = value; }

        std::shared_ptr<bool> get_can_see_organic_insights() const { return can_see_organic_insights; }
        void set_can_see_organic_insights(std::shared_ptr<bool> value) { this->can_see_organic_insights = value; }

        std::shared_ptr<bool> get_show_insights_terms() const { return show_insights_terms; }
        void set_show_insights_terms(std::shared_ptr<bool> value) { this->show_insights_terms = value; }

        std::shared_ptr<int64_t> get_total_igtv_videos() const { return total_igtv_videos; }
        void set_total_igtv_videos(std::shared_ptr<int64_t> value) { this->total_igtv_videos = value; }

        std::shared_ptr<std::string> get_reel_auto_archive() const { return reel_auto_archive; }
        void set_reel_auto_archive(std::shared_ptr<std::string> value) { this->reel_auto_archive = value; }

        std::shared_ptr<bool> get_has_placed_orders() const { return has_placed_orders; }
        void set_has_placed_orders(std::shared_ptr<bool> value) { this->has_placed_orders = value; }

        std::shared_ptr<std::string> get_allowed_commenter_type() const { return allowed_commenter_type; }
        void set_allowed_commenter_type(std::shared_ptr<std::string> value) { this->allowed_commenter_type = value; }

        std::shared_ptr<Nametag> get_nametag() const { return nametag; }
        void set_nametag(std::shared_ptr<Nametag> value) { this->nametag = value; }

        std::shared_ptr<bool> get_is_using_unified_inbox_for_direct() const { return is_using_unified_inbox_for_direct; }
        void set_is_using_unified_inbox_for_direct(std::shared_ptr<bool> value) { this->is_using_unified_inbox_for_direct = value; }

        std::shared_ptr<int64_t> get_biz_user_inbox_state() const { return biz_user_inbox_state; }
        void set_biz_user_inbox_state(std::shared_ptr<int64_t> value) { this->biz_user_inbox_state = value; }

        std::shared_ptr<bool> get_wa_addressable() const { return wa_addressable; }
        void set_wa_addressable(std::shared_ptr<bool> value) { this->wa_addressable = value; }

        std::shared_ptr<int64_t> get_wa_eligibility() const { return wa_eligibility; }
        void set_wa_eligibility(std::shared_ptr<int64_t> value) { this->wa_eligibility = value; }

        std::shared_ptr<double> get_interop_messaging_user_fbid() const { return interop_messaging_user_fbid; }
        void set_interop_messaging_user_fbid(std::shared_ptr<double> value) { this->interop_messaging_user_fbid = value; }

        std::shared_ptr<bool> get_can_see_primary_country_in_settings() const { return can_see_primary_country_in_settings; }
        void set_can_see_primary_country_in_settings(std::shared_ptr<bool> value) { this->can_see_primary_country_in_settings = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_account_badges() const { return account_badges; }
        void set_account_badges(std::shared_ptr<std::vector<nlohmann::json>> value) { this->account_badges = value; }

        std::shared_ptr<double> get_fbid_v2() const { return fbid_v2; }
        void set_fbid_v2(std::shared_ptr<double> value) { this->fbid_v2 = value; }

        std::shared_ptr<bool> get_allow_contacts_sync() const { return allow_contacts_sync; }
        void set_allow_contacts_sync(std::shared_ptr<bool> value) { this->allow_contacts_sync = value; }

        std::shared_ptr<std::string> get_phone_number() const { return phone_number; }
        void set_phone_number(std::shared_ptr<std::string> value) { this->phone_number = value; }
    };

    class LoginRequest {
        public:
        LoginRequest() = default;
        virtual ~LoginRequest() = default;

        private:
        std::shared_ptr<LoggedInUser> logged_in_user;
        std::shared_ptr<std::string> status;

        public:
        std::shared_ptr<LoggedInUser> get_logged_in_user() const { return logged_in_user; }
        void set_logged_in_user(std::shared_ptr<LoggedInUser> value) { this->logged_in_user = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, IgTypes::Nametag & x);
    void to_json(json & j, const IgTypes::Nametag & x);

    void from_json(const json & j, IgTypes::LoggedInUser & x);
    void to_json(json & j, const IgTypes::LoggedInUser & x);

    void from_json(const json & j, IgTypes::LoginRequest & x);
    void to_json(json & j, const IgTypes::LoginRequest & x);

    inline void from_json(const json & j, IgTypes::Nametag& x) {
        x.set_mode(IgTypes::get_optional<int64_t>(j, "mode"));
        x.set_gradient(IgTypes::get_optional<int64_t>(j, "gradient"));
        x.set_emoji(IgTypes::get_optional<std::string>(j, "emoji"));
        x.set_selfie_sticker(IgTypes::get_optional<int64_t>(j, "selfie_sticker"));
    }

    inline void to_json(json & j, const IgTypes::Nametag & x) {
        j = json::object();
        j["mode"] = x.get_mode();
        j["gradient"] = x.get_gradient();
        j["emoji"] = x.get_emoji();
        j["selfie_sticker"] = x.get_selfie_sticker();
    }

    inline void from_json(const json & j, IgTypes::LoggedInUser& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_username(IgTypes::get_optional<std::string>(j, "username"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
        x.set_has_anonymous_profile_picture(IgTypes::get_optional<bool>(j, "has_anonymous_profile_picture"));
        x.set_can_boost_post(IgTypes::get_optional<bool>(j, "can_boost_post"));
        x.set_is_business(IgTypes::get_optional<bool>(j, "is_business"));
        x.set_account_type(IgTypes::get_optional<int64_t>(j, "account_type"));
        x.set_professional_conversion_suggested_account_type(IgTypes::get_optional<int64_t>(j, "professional_conversion_suggested_account_type"));
        x.set_is_call_to_action_enabled(IgTypes::get_untyped(j, "is_call_to_action_enabled"));
        x.set_can_see_organic_insights(IgTypes::get_optional<bool>(j, "can_see_organic_insights"));
        x.set_show_insights_terms(IgTypes::get_optional<bool>(j, "show_insights_terms"));
        x.set_total_igtv_videos(IgTypes::get_optional<int64_t>(j, "total_igtv_videos"));
        x.set_reel_auto_archive(IgTypes::get_optional<std::string>(j, "reel_auto_archive"));
        x.set_has_placed_orders(IgTypes::get_optional<bool>(j, "has_placed_orders"));
        x.set_allowed_commenter_type(IgTypes::get_optional<std::string>(j, "allowed_commenter_type"));
        x.set_nametag(IgTypes::get_optional<IgTypes::Nametag>(j, "nametag"));
        x.set_is_using_unified_inbox_for_direct(IgTypes::get_optional<bool>(j, "is_using_unified_inbox_for_direct"));
        x.set_biz_user_inbox_state(IgTypes::get_optional<int64_t>(j, "biz_user_inbox_state"));
        x.set_wa_addressable(IgTypes::get_optional<bool>(j, "wa_addressable"));
        x.set_wa_eligibility(IgTypes::get_optional<int64_t>(j, "wa_eligibility"));
        x.set_interop_messaging_user_fbid(IgTypes::get_optional<double>(j, "interop_messaging_user_fbid"));
        x.set_can_see_primary_country_in_settings(IgTypes::get_optional<bool>(j, "can_see_primary_country_in_settings"));
        x.set_account_badges(IgTypes::get_optional<std::vector<json>>(j, "account_badges"));
        x.set_fbid_v2(IgTypes::get_optional<double>(j, "fbid_v2"));
        x.set_allow_contacts_sync(IgTypes::get_optional<bool>(j, "allow_contacts_sync"));
        x.set_phone_number(IgTypes::get_optional<std::string>(j, "phone_number"));
    }

    inline void to_json(json & j, const IgTypes::LoggedInUser & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["username"] = x.get_username();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
        j["has_anonymous_profile_picture"] = x.get_has_anonymous_profile_picture();
        j["can_boost_post"] = x.get_can_boost_post();
        j["is_business"] = x.get_is_business();
        j["account_type"] = x.get_account_type();
        j["professional_conversion_suggested_account_type"] = x.get_professional_conversion_suggested_account_type();
        j["is_call_to_action_enabled"] = x.get_is_call_to_action_enabled();
        j["can_see_organic_insights"] = x.get_can_see_organic_insights();
        j["show_insights_terms"] = x.get_show_insights_terms();
        j["total_igtv_videos"] = x.get_total_igtv_videos();
        j["reel_auto_archive"] = x.get_reel_auto_archive();
        j["has_placed_orders"] = x.get_has_placed_orders();
        j["allowed_commenter_type"] = x.get_allowed_commenter_type();
        j["nametag"] = x.get_nametag();
        j["is_using_unified_inbox_for_direct"] = x.get_is_using_unified_inbox_for_direct();
        j["biz_user_inbox_state"] = x.get_biz_user_inbox_state();
        j["wa_addressable"] = x.get_wa_addressable();
        j["wa_eligibility"] = x.get_wa_eligibility();
        j["interop_messaging_user_fbid"] = x.get_interop_messaging_user_fbid();
        j["can_see_primary_country_in_settings"] = x.get_can_see_primary_country_in_settings();
        j["account_badges"] = x.get_account_badges();
        j["fbid_v2"] = x.get_fbid_v2();
        j["allow_contacts_sync"] = x.get_allow_contacts_sync();
        j["phone_number"] = x.get_phone_number();
    }

    inline void from_json(const json & j, IgTypes::LoginRequest& x) {
        x.set_logged_in_user(IgTypes::get_optional<IgTypes::LoggedInUser>(j, "logged_in_user"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
    }

    inline void to_json(json & j, const IgTypes::LoginRequest & x) {
        j = json::object();
        j["logged_in_user"] = x.get_logged_in_user();
        j["status"] = x.get_status();
    }
}
