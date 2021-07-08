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

    class UserComment {
        public:
        UserComment() = default;
        virtual ~UserComment() = default;

        private:
        std::shared_ptr<int64_t> pk;
        std::shared_ptr<std::string> UserCommentname;
        std::shared_ptr<std::string> full_name;
        std::shared_ptr<bool> is_private;
        std::shared_ptr<std::string> profile_pic_url;
        std::shared_ptr<std::string> profile_pic_id;
        std::shared_ptr<bool> is_verified;
        std::shared_ptr<int64_t> follow_friction_type;
        std::shared_ptr<bool> is_mentionable;
        std::shared_ptr<int64_t> latest_reel_media;
        std::shared_ptr<int64_t> latest_besties_reel_media;

        public:
        std::shared_ptr<int64_t> get_pk() const { return pk; }
        void set_pk(std::shared_ptr<int64_t> value) { this->pk = value; }

        std::shared_ptr<std::string> get_UserCommentname() const { return UserCommentname; }
        void set_UserCommentname(std::shared_ptr<std::string> value) { this->UserCommentname = value; }

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

        std::shared_ptr<bool> get_is_mentionable() const { return is_mentionable; }
        void set_is_mentionable(std::shared_ptr<bool> value) { this->is_mentionable = value; }

        std::shared_ptr<int64_t> get_latest_reel_media() const { return latest_reel_media; }
        void set_latest_reel_media(std::shared_ptr<int64_t> value) { this->latest_reel_media = value; }

        std::shared_ptr<int64_t> get_latest_besties_reel_media() const { return latest_besties_reel_media; }
        void set_latest_besties_reel_media(std::shared_ptr<int64_t> value) { this->latest_besties_reel_media = value; }
    };

    class Comment {
        public:
        Comment() = default;
        virtual ~Comment() = default;

        private:
        std::shared_ptr<double> pk;
        std::shared_ptr<int64_t> UserComment_id;
        std::shared_ptr<std::string> text;
        std::shared_ptr<int64_t> type;
        std::shared_ptr<int64_t> created_at;
        std::shared_ptr<int64_t> created_at_utc;
        std::shared_ptr<std::string> content_type;
        std::shared_ptr<std::string> status;
        std::shared_ptr<int64_t> bit_flags;
        std::shared_ptr<bool> did_report_as_spam;
        std::shared_ptr<bool> share_enabled;
        std::shared_ptr<UserComment> userComment;
        std::shared_ptr<bool> is_covered;
        std::shared_ptr<bool> has_liked_comment;
        std::shared_ptr<int64_t> comment_like_count;
        std::shared_ptr<std::string> inline_composer_display_condition;
        std::shared_ptr<int64_t> private_reply_status;

        public:
        std::shared_ptr<double> get_pk() const { return pk; }
        void set_pk(std::shared_ptr<double> value) { this->pk = value; }

        std::shared_ptr<int64_t> get_UserComment_id() const { return UserComment_id; }
        void set_UserComment_id(std::shared_ptr<int64_t> value) { this->UserComment_id = value; }

        std::shared_ptr<std::string> get_text() const { return text; }
        void set_text(std::shared_ptr<std::string> value) { this->text = value; }

        std::shared_ptr<int64_t> get_type() const { return type; }
        void set_type(std::shared_ptr<int64_t> value) { this->type = value; }

        std::shared_ptr<int64_t> get_created_at() const { return created_at; }
        void set_created_at(std::shared_ptr<int64_t> value) { this->created_at = value; }

        std::shared_ptr<int64_t> get_created_at_utc() const { return created_at_utc; }
        void set_created_at_utc(std::shared_ptr<int64_t> value) { this->created_at_utc = value; }

        std::shared_ptr<std::string> get_content_type() const { return content_type; }
        void set_content_type(std::shared_ptr<std::string> value) { this->content_type = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }

        std::shared_ptr<int64_t> get_bit_flags() const { return bit_flags; }
        void set_bit_flags(std::shared_ptr<int64_t> value) { this->bit_flags = value; }

        std::shared_ptr<bool> get_did_report_as_spam() const { return did_report_as_spam; }
        void set_did_report_as_spam(std::shared_ptr<bool> value) { this->did_report_as_spam = value; }

        std::shared_ptr<bool> get_share_enabled() const { return share_enabled; }
        void set_share_enabled(std::shared_ptr<bool> value) { this->share_enabled = value; }

        std::shared_ptr<UserComment> get_UserComment() const { return userComment; }
        void set_UserComment(std::shared_ptr<UserComment> value) { this->userComment = value; }

        std::shared_ptr<bool> get_is_covered() const { return is_covered; }
        void set_is_covered(std::shared_ptr<bool> value) { this->is_covered = value; }

        std::shared_ptr<bool> get_has_liked_comment() const { return has_liked_comment; }
        void set_has_liked_comment(std::shared_ptr<bool> value) { this->has_liked_comment = value; }

        std::shared_ptr<int64_t> get_comment_like_count() const { return comment_like_count; }
        void set_comment_like_count(std::shared_ptr<int64_t> value) { this->comment_like_count = value; }

        std::shared_ptr<std::string> get_inline_composer_display_condition() const { return inline_composer_display_condition; }
        void set_inline_composer_display_condition(std::shared_ptr<std::string> value) { this->inline_composer_display_condition = value; }

        std::shared_ptr<int64_t> get_private_reply_status() const { return private_reply_status; }
        void set_private_reply_status(std::shared_ptr<int64_t> value) { this->private_reply_status = value; }
    };

    class QuickResponseEmoji {
        public:
        QuickResponseEmoji() = default;
        virtual ~QuickResponseEmoji() = default;

        private:
        std::shared_ptr<std::string> unicode;

        public:
        std::shared_ptr<std::string> get_unicode() const { return unicode; }
        void set_unicode(std::shared_ptr<std::string> value) { this->unicode = value; }
    };

    class UserCommentsRequest {
        public:
        UserCommentsRequest() = default;
        virtual ~UserCommentsRequest() = default;

        private:
        std::shared_ptr<bool> comment_likes_enabled;
        std::shared_ptr<std::vector<Comment>> comments;
        std::shared_ptr<int64_t> comment_count;
        nlohmann::json caption;
        std::shared_ptr<bool> caption_is_edited;
        std::shared_ptr<bool> has_more_comments;
        std::shared_ptr<bool> has_more_headload_comments;
        std::shared_ptr<std::string> media_header_display;
        std::shared_ptr<bool> initiate_at_top;
        std::shared_ptr<bool> insert_new_comment_to_top;
        std::shared_ptr<bool> display_realtime_typing_indicator;
        std::shared_ptr<std::vector<QuickResponseEmoji>> quick_response_emojis;
        std::shared_ptr<std::vector<nlohmann::json>> preview_comments;
        std::shared_ptr<bool> can_view_more_preview_comments;
        std::shared_ptr<int64_t> scroll_behavior;
        std::shared_ptr<std::string> status;

        public:
        std::shared_ptr<bool> get_comment_likes_enabled() const { return comment_likes_enabled; }
        void set_comment_likes_enabled(std::shared_ptr<bool> value) { this->comment_likes_enabled = value; }

        std::shared_ptr<std::vector<Comment>> get_comments() const { return comments; }
        void set_comments(std::shared_ptr<std::vector<Comment>> value) { this->comments = value; }

        std::shared_ptr<int64_t> get_comment_count() const { return comment_count; }
        void set_comment_count(std::shared_ptr<int64_t> value) { this->comment_count = value; }

        const nlohmann::json & get_caption() const { return caption; }
        nlohmann::json & get_mutable_caption() { return caption; }
        void set_caption(const nlohmann::json & value) { this->caption = value; }

        std::shared_ptr<bool> get_caption_is_edited() const { return caption_is_edited; }
        void set_caption_is_edited(std::shared_ptr<bool> value) { this->caption_is_edited = value; }

        std::shared_ptr<bool> get_has_more_comments() const { return has_more_comments; }
        void set_has_more_comments(std::shared_ptr<bool> value) { this->has_more_comments = value; }

        std::shared_ptr<bool> get_has_more_headload_comments() const { return has_more_headload_comments; }
        void set_has_more_headload_comments(std::shared_ptr<bool> value) { this->has_more_headload_comments = value; }

        std::shared_ptr<std::string> get_media_header_display() const { return media_header_display; }
        void set_media_header_display(std::shared_ptr<std::string> value) { this->media_header_display = value; }

        std::shared_ptr<bool> get_initiate_at_top() const { return initiate_at_top; }
        void set_initiate_at_top(std::shared_ptr<bool> value) { this->initiate_at_top = value; }

        std::shared_ptr<bool> get_insert_new_comment_to_top() const { return insert_new_comment_to_top; }
        void set_insert_new_comment_to_top(std::shared_ptr<bool> value) { this->insert_new_comment_to_top = value; }

        std::shared_ptr<bool> get_display_realtime_typing_indicator() const { return display_realtime_typing_indicator; }
        void set_display_realtime_typing_indicator(std::shared_ptr<bool> value) { this->display_realtime_typing_indicator = value; }

        std::shared_ptr<std::vector<QuickResponseEmoji>> get_quick_response_emojis() const { return quick_response_emojis; }
        void set_quick_response_emojis(std::shared_ptr<std::vector<QuickResponseEmoji>> value) { this->quick_response_emojis = value; }

        std::shared_ptr<std::vector<nlohmann::json>> get_preview_comments() const { return preview_comments; }
        void set_preview_comments(std::shared_ptr<std::vector<nlohmann::json>> value) { this->preview_comments = value; }

        std::shared_ptr<bool> get_can_view_more_preview_comments() const { return can_view_more_preview_comments; }
        void set_can_view_more_preview_comments(std::shared_ptr<bool> value) { this->can_view_more_preview_comments = value; }

        std::shared_ptr<int64_t> get_scroll_behavior() const { return scroll_behavior; }
        void set_scroll_behavior(std::shared_ptr<int64_t> value) { this->scroll_behavior = value; }

        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, IgTypes::UserComment & x);
    void to_json(json & j, const IgTypes::UserComment & x);

    void from_json(const json & j, IgTypes::Comment & x);
    void to_json(json & j, const IgTypes::Comment & x);

    void from_json(const json & j, IgTypes::QuickResponseEmoji & x);
    void to_json(json & j, const IgTypes::QuickResponseEmoji & x);

    void from_json(const json & j, IgTypes::UserCommentsRequest & x);
    void to_json(json & j, const IgTypes::UserCommentsRequest & x);

    inline void from_json(const json & j, IgTypes::UserComment& x) {
        x.set_pk(IgTypes::get_optional<int64_t>(j, "pk"));
        x.set_UserCommentname(IgTypes::get_optional<std::string>(j, "UserCommentname"));
        x.set_full_name(IgTypes::get_optional<std::string>(j, "full_name"));
        x.set_is_private(IgTypes::get_optional<bool>(j, "is_private"));
        x.set_profile_pic_url(IgTypes::get_optional<std::string>(j, "profile_pic_url"));
        x.set_profile_pic_id(IgTypes::get_optional<std::string>(j, "profile_pic_id"));
        x.set_is_verified(IgTypes::get_optional<bool>(j, "is_verified"));
        x.set_follow_friction_type(IgTypes::get_optional<int64_t>(j, "follow_friction_type"));
        x.set_is_mentionable(IgTypes::get_optional<bool>(j, "is_mentionable"));
        x.set_latest_reel_media(IgTypes::get_optional<int64_t>(j, "latest_reel_media"));
        x.set_latest_besties_reel_media(IgTypes::get_optional<int64_t>(j, "latest_besties_reel_media"));
    }

    inline void to_json(json & j, const IgTypes::UserComment & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["UserCommentname"] = x.get_UserCommentname();
        j["full_name"] = x.get_full_name();
        j["is_private"] = x.get_is_private();
        j["profile_pic_url"] = x.get_profile_pic_url();
        j["profile_pic_id"] = x.get_profile_pic_id();
        j["is_verified"] = x.get_is_verified();
        j["follow_friction_type"] = x.get_follow_friction_type();
        j["is_mentionable"] = x.get_is_mentionable();
        j["latest_reel_media"] = x.get_latest_reel_media();
        j["latest_besties_reel_media"] = x.get_latest_besties_reel_media();
    }

    inline void from_json(const json & j, IgTypes::Comment& x) {
        x.set_pk(IgTypes::get_optional<double>(j, "pk"));
        x.set_UserComment_id(IgTypes::get_optional<int64_t>(j, "UserComment_id"));
        x.set_text(IgTypes::get_optional<std::string>(j, "text"));
        x.set_type(IgTypes::get_optional<int64_t>(j, "type"));
        x.set_created_at(IgTypes::get_optional<int64_t>(j, "created_at"));
        x.set_created_at_utc(IgTypes::get_optional<int64_t>(j, "created_at_utc"));
        x.set_content_type(IgTypes::get_optional<std::string>(j, "content_type"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
        x.set_bit_flags(IgTypes::get_optional<int64_t>(j, "bit_flags"));
        x.set_did_report_as_spam(IgTypes::get_optional<bool>(j, "did_report_as_spam"));
        x.set_share_enabled(IgTypes::get_optional<bool>(j, "share_enabled"));
        x.set_UserComment(IgTypes::get_optional<IgTypes::UserComment>(j, "UserComment"));
        x.set_is_covered(IgTypes::get_optional<bool>(j, "is_covered"));
        x.set_has_liked_comment(IgTypes::get_optional<bool>(j, "has_liked_comment"));
        x.set_comment_like_count(IgTypes::get_optional<int64_t>(j, "comment_like_count"));
        x.set_inline_composer_display_condition(IgTypes::get_optional<std::string>(j, "inline_composer_display_condition"));
        x.set_private_reply_status(IgTypes::get_optional<int64_t>(j, "private_reply_status"));
    }

    inline void to_json(json & j, const IgTypes::Comment & x) {
        j = json::object();
        j["pk"] = x.get_pk();
        j["UserComment_id"] = x.get_UserComment_id();
        j["text"] = x.get_text();
        j["type"] = x.get_type();
        j["created_at"] = x.get_created_at();
        j["created_at_utc"] = x.get_created_at_utc();
        j["content_type"] = x.get_content_type();
        j["status"] = x.get_status();
        j["bit_flags"] = x.get_bit_flags();
        j["did_report_as_spam"] = x.get_did_report_as_spam();
        j["share_enabled"] = x.get_share_enabled();
        j["UserComment"] = x.get_UserComment();
        j["is_covered"] = x.get_is_covered();
        j["has_liked_comment"] = x.get_has_liked_comment();
        j["comment_like_count"] = x.get_comment_like_count();
        j["inline_composer_display_condition"] = x.get_inline_composer_display_condition();
        j["private_reply_status"] = x.get_private_reply_status();
    }

    inline void from_json(const json & j, IgTypes::QuickResponseEmoji& x) {
        x.set_unicode(IgTypes::get_optional<std::string>(j, "unicode"));
    }

    inline void to_json(json & j, const IgTypes::QuickResponseEmoji & x) {
        j = json::object();
        j["unicode"] = x.get_unicode();
    }

    inline void from_json(const json & j, IgTypes::UserCommentsRequest& x) {
        x.set_comment_likes_enabled(IgTypes::get_optional<bool>(j, "comment_likes_enabled"));
        x.set_comments(IgTypes::get_optional<std::vector<IgTypes::Comment>>(j, "comments"));
        x.set_comment_count(IgTypes::get_optional<int64_t>(j, "comment_count"));
        x.set_caption(IgTypes::get_untyped(j, "caption"));
        x.set_caption_is_edited(IgTypes::get_optional<bool>(j, "caption_is_edited"));
        x.set_has_more_comments(IgTypes::get_optional<bool>(j, "has_more_comments"));
        x.set_has_more_headload_comments(IgTypes::get_optional<bool>(j, "has_more_headload_comments"));
        x.set_media_header_display(IgTypes::get_optional<std::string>(j, "media_header_display"));
        x.set_initiate_at_top(IgTypes::get_optional<bool>(j, "initiate_at_top"));
        x.set_insert_new_comment_to_top(IgTypes::get_optional<bool>(j, "insert_new_comment_to_top"));
        x.set_display_realtime_typing_indicator(IgTypes::get_optional<bool>(j, "display_realtime_typing_indicator"));
        x.set_quick_response_emojis(IgTypes::get_optional<std::vector<IgTypes::QuickResponseEmoji>>(j, "quick_response_emojis"));
        x.set_preview_comments(IgTypes::get_optional<std::vector<json>>(j, "preview_comments"));
        x.set_can_view_more_preview_comments(IgTypes::get_optional<bool>(j, "can_view_more_preview_comments"));
        x.set_scroll_behavior(IgTypes::get_optional<int64_t>(j, "scroll_behavior"));
        x.set_status(IgTypes::get_optional<std::string>(j, "status"));
    }

    inline void to_json(json & j, const IgTypes::UserCommentsRequest & x) {
        j = json::object();
        j["comment_likes_enabled"] = x.get_comment_likes_enabled();
        j["comments"] = x.get_comments();
        j["comment_count"] = x.get_comment_count();
        j["caption"] = x.get_caption();
        j["caption_is_edited"] = x.get_caption_is_edited();
        j["has_more_comments"] = x.get_has_more_comments();
        j["has_more_headload_comments"] = x.get_has_more_headload_comments();
        j["media_header_display"] = x.get_media_header_display();
        j["initiate_at_top"] = x.get_initiate_at_top();
        j["insert_new_comment_to_top"] = x.get_insert_new_comment_to_top();
        j["display_realtime_typing_indicator"] = x.get_display_realtime_typing_indicator();
        j["quick_response_emojis"] = x.get_quick_response_emojis();
        j["preview_comments"] = x.get_preview_comments();
        j["can_view_more_preview_comments"] = x.get_can_view_more_preview_comments();
        j["scroll_behavior"] = x.get_scroll_behavior();
        j["status"] = x.get_status();
    }
}
