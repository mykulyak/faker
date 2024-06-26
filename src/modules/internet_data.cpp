#include "internet_data.h"

namespace faker::internet::data {
const std::array<std::string_view, 6> domain_suffixes
    = { "com", "biz", "info", "name", "net", "org" };

const std::array<std::string_view, 4> email_hosts
    = { "gmail.com", "yahoo.com", "hotmail.com", "outlook.com" };

const std::array<std::string_view, 3> email_example_hosts
    = { "example.org", "example.com", "example.net" };

// Source: https://www.unicode.org/Public/emoji/13.1/emoji-test.txt
// Others: https://www.unicode.org/Public/emoji/
// Versions: https://www.unicode.org/versions/enumeratedversions.html

const std::array<std::string_view, 156> smiley_emojis = { "😀", "😃", "😄", "😁", "😆", "😅", "🤣",
    "😂", "🙂", "🙃", "😉", "😊", "😇", "🥰", "😍", "🤩", "😘", "😗", "☺️", "😚", "😙", "🥲", "😋",
    "😛", "😜", "🤪", "😝", "🤑", "🤗", "🤭", "🤫", "🤔", "🤐", "🤨", "😐", "😑", "😶",
    "😶‍🌫️", "😏", "😒", "🙄", "😬", "😮‍💨", "🤥", "😌", "😔", "😪", "🤤", "😴",
    "😷", "🤒", "🤕", "🤢", "🤮", "🤧", "🥵", "🥶", "🥴", "😵", "😵‍💫", "🤯", "🤠", "🥳",
    "🥸", "😎", "🤓", "🧐", "😕", "😟", "🙁", "☹️", "😮", "😯", "😲", "😳", "🥺", "😦", "😧", "😨",
    "😰", "😥", "😢", "😭", "😱", "😖", "😣", "😞", "😓", "😩", "😫", "🥱", "😤", "😡", "😠", "🤬",
    "😈", "👿", "💀", "☠️", "💩", "🤡", "👹", "👺", "👻", "👽", "👾", "🤖", "😺", "😸", "😹", "😻",
    "😼", "😽", "🙀", "😿", "😾", "🙈", "🙉", "🙊", "💋", "💌", "💘", "💝", "💖", "💗", "💓", "💞",
    "💕", "💟", "❣️", "💔", "❤️‍🔥", "❤️‍🩹", "❤️", "🧡", "💛", "💚", "💙", "💜",
    "🤎", "🖤", "🤍", "💯", "💢", "💥", "💫", "💦", "💨", "🕳️", "💣", "💬", "👁️‍🗨️",
    "🗨️", "🗯️", "💭", "💤" };

const std::array<std::string_view, 246> body_emojis = { "👋", "👋🏻", "👋🏼", "👋🏽", "👋🏾",
    "👋🏿", "🤚", "🤚🏻", "🤚🏼", "🤚🏽", "🤚🏾", "🤚🏿", "🖐️", "🖐🏻", "🖐🏼", "🖐🏽", "🖐🏾",
    "🖐🏿", "✋", "✋🏻", "✋🏼", "✋🏽", "✋🏾", "✋🏿", "🖖", "🖖🏻", "🖖🏼", "🖖🏽", "🖖🏾",
    "🖖🏿", "👌", "👌🏻", "👌🏼", "👌🏽", "👌🏾", "👌🏿", "🤌", "🤌🏻", "🤌🏼", "🤌🏽", "🤌🏾",
    "🤌🏿", "🤏", "🤏🏻", "🤏🏼", "🤏🏽", "🤏🏾", "🤏🏿", "✌️", "✌🏻", "✌🏼", "✌🏽", "✌🏾", "✌🏿",
    "🤞", "🤞🏻", "🤞🏼", "🤞🏽", "🤞🏾", "🤞🏿", "🤟", "🤟🏻", "🤟🏼", "🤟🏽", "🤟🏾", "🤟🏿",
    "🤘", "🤘🏻", "🤘🏼", "🤘🏽", "🤘🏾", "🤘🏿", "🤙", "🤙🏻", "🤙🏼", "🤙🏽", "🤙🏾", "🤙🏿",
    "👈", "👈🏻", "👈🏼", "👈🏽", "👈🏾", "👈🏿", "👉", "👉🏻", "👉🏼", "👉🏽", "👉🏾", "👉🏿",
    "👆", "👆🏻", "👆🏼", "👆🏽", "👆🏾", "👆🏿", "🖕", "🖕🏻", "🖕🏼", "🖕🏽", "🖕🏾", "🖕🏿",
    "👇", "👇🏻", "👇🏼", "👇🏽", "👇🏾", "👇🏿", "☝️", "☝🏻", "☝🏼", "☝🏽", "☝🏾", "☝🏿", "👍",
    "👍🏻", "👍🏼", "👍🏽", "👍🏾", "👍🏿", "👎", "👎🏻", "👎🏼", "👎🏽", "👎🏾", "👎🏿", "✊",
    "✊🏻", "✊🏼", "✊🏽", "✊🏾", "✊🏿", "👊", "👊🏻", "👊🏼", "👊🏽", "👊🏾", "👊🏿", "🤛",
    "🤛🏻", "🤛🏼", "🤛🏽", "🤛🏾", "🤛🏿", "🤜", "🤜🏻", "🤜🏼", "🤜🏽", "🤜🏾", "🤜🏿", "👏",
    "👏🏻", "👏🏼", "👏🏽", "👏🏾", "👏🏿", "🙌", "🙌🏻", "🙌🏼", "🙌🏽", "🙌🏾", "🙌🏿", "👐",
    "👐🏻", "👐🏼", "👐🏽", "👐🏾", "👐🏿", "🤲", "🤲🏻", "🤲🏼", "🤲🏽", "🤲🏾", "🤲🏿", "🤝",
    "🙏", "🙏🏻", "🙏🏼", "🙏🏽", "🙏🏾", "🙏🏿", "✍️", "✍🏻", "✍🏼", "✍🏽", "✍🏾", "✍🏿", "💅",
    "💅🏻", "💅🏼", "💅🏽", "💅🏾", "💅🏿", "🤳", "🤳🏻", "🤳🏼", "🤳🏽", "🤳🏾", "🤳🏿", "💪",
    "💪🏻", "💪🏼", "💪🏽", "💪🏾", "💪🏿", "🦾", "🦿", "🦵", "🦵🏻", "🦵🏼", "🦵🏽", "🦵🏾",
    "🦵🏿", "🦶", "🦶🏻", "🦶🏼", "🦶🏽", "🦶🏾", "🦶🏿", "👂", "👂🏻", "👂🏼", "👂🏽", "👂🏾",
    "👂🏿", "🦻", "🦻🏻", "🦻🏼", "🦻🏽", "🦻🏾", "🦻🏿", "👃", "👃🏻", "👃🏼", "👃🏽", "👃🏾",
    "👃🏿", "🧠", "🫀", "🫁", "🦷", "🦴", "👀", "👁️", "👅", "👄" };

const std::array<std::string_view, 1803> person_emojis = { "👶", "👶🏻", "👶🏼", "👶🏽", "👶🏾",
    "👶🏿", "🧒", "🧒🏻", "🧒🏼", "🧒🏽", "🧒🏾", "🧒🏿", "👦", "👦🏻", "👦🏼", "👦🏽", "👦🏾",
    "👦🏿", "👧", "👧🏻", "👧🏼", "👧🏽", "👧🏾", "👧🏿", "🧑", "🧑🏻", "🧑🏼", "🧑🏽", "🧑🏾",
    "🧑🏿", "👱", "👱🏻", "👱🏼", "👱🏽", "👱🏾", "👱🏿", "👨", "👨🏻", "👨🏼", "👨🏽", "👨🏾",
    "👨🏿", "🧔", "🧔🏻", "🧔🏼", "🧔🏽", "🧔🏾", "🧔🏿", "🧔‍♂️", "🧔🏻‍♂️",
    "🧔🏼‍♂️", "🧔🏽‍♂️", "🧔🏾‍♂️", "🧔🏿‍♂️",
    "🧔‍♀️", "🧔🏻‍♀️", "🧔🏼‍♀️", "🧔🏽‍♀️",
    "🧔🏾‍♀️", "🧔🏿‍♀️", "👨‍🦰", "👨🏻‍🦰", "👨🏼‍🦰",
    "👨🏽‍🦰", "👨🏾‍🦰", "👨🏿‍🦰", "👨‍🦱", "👨🏻‍🦱",
    "👨🏼‍🦱", "👨🏽‍🦱", "👨🏾‍🦱", "👨🏿‍🦱", "👨‍🦳",
    "👨🏻‍🦳", "👨🏼‍🦳", "👨🏽‍🦳", "👨🏾‍🦳", "👨🏿‍🦳",
    "👨‍🦲", "👨🏻‍🦲", "👨🏼‍🦲", "👨🏽‍🦲", "👨🏾‍🦲",
    "👨🏿‍🦲", "👩", "👩🏻", "👩🏼", "👩🏽", "👩🏾", "👩🏿", "👩‍🦰",
    "👩🏻‍🦰", "👩🏼‍🦰", "👩🏽‍🦰", "👩🏾‍🦰", "👩🏿‍🦰",
    "🧑‍🦰", "🧑🏻‍🦰", "🧑🏼‍🦰", "🧑🏽‍🦰", "🧑🏾‍🦰",
    "🧑🏿‍🦰", "👩‍🦱", "👩🏻‍🦱", "👩🏼‍🦱", "👩🏽‍🦱",
    "👩🏾‍🦱", "👩🏿‍🦱", "🧑‍🦱", "🧑🏻‍🦱", "🧑🏼‍🦱",
    "🧑🏽‍🦱", "🧑🏾‍🦱", "🧑🏿‍🦱", "👩‍🦳", "👩🏻‍🦳",
    "👩🏼‍🦳", "👩🏽‍🦳", "👩🏾‍🦳", "👩🏿‍🦳", "🧑‍🦳",
    "🧑🏻‍🦳", "🧑🏼‍🦳", "🧑🏽‍🦳", "🧑🏾‍🦳", "🧑🏿‍🦳",
    "👩‍🦲", "👩🏻‍🦲", "👩🏼‍🦲", "👩🏽‍🦲", "👩🏾‍🦲",
    "👩🏿‍🦲", "🧑‍🦲", "🧑🏻‍🦲", "🧑🏼‍🦲", "🧑🏽‍🦲",
    "🧑🏾‍🦲", "🧑🏿‍🦲", "👱‍♀️", "👱🏻‍♀️", "👱🏼‍♀️",
    "👱🏽‍♀️", "👱🏾‍♀️", "👱🏿‍♀️", "👱‍♂️",
    "👱🏻‍♂️", "👱🏼‍♂️", "👱🏽‍♂️", "👱🏾‍♂️",
    "👱🏿‍♂️", "🧓", "🧓🏻", "🧓🏼", "🧓🏽", "🧓🏾", "🧓🏿", "👴", "👴🏻", "👴🏼", "👴🏽",
    "👴🏾", "👴🏿", "👵", "👵🏻", "👵🏼", "👵🏽", "👵🏾", "👵🏿", "🙍", "🙍🏻", "🙍🏼", "🙍🏽",
    "🙍🏾", "🙍🏿", "🙍‍♂️", "🙍🏻‍♂️", "🙍🏼‍♂️", "🙍🏽‍♂️",
    "🙍🏾‍♂️", "🙍🏿‍♂️", "🙍‍♀️", "🙍🏻‍♀️",
    "🙍🏼‍♀️", "🙍🏽‍♀️", "🙍🏾‍♀️", "🙍🏿‍♀️", "🙎",
    "🙎🏻", "🙎🏼", "🙎🏽", "🙎🏾", "🙎🏿", "🙎‍♂️", "🙎🏻‍♂️",
    "🙎🏼‍♂️", "🙎🏽‍♂️", "🙎🏾‍♂️", "🙎🏿‍♂️",
    "🙎‍♀️", "🙎🏻‍♀️", "🙎🏼‍♀️", "🙎🏽‍♀️",
    "🙎🏾‍♀️", "🙎🏿‍♀️", "🙅", "🙅🏻", "🙅🏼", "🙅🏽", "🙅🏾", "🙅🏿",
    "🙅‍♂️", "🙅🏻‍♂️", "🙅🏼‍♂️", "🙅🏽‍♂️",
    "🙅🏾‍♂️", "🙅🏿‍♂️", "🙅‍♀️", "🙅🏻‍♀️",
    "🙅🏼‍♀️", "🙅🏽‍♀️", "🙅🏾‍♀️", "🙅🏿‍♀️", "🙆",
    "🙆🏻", "🙆🏼", "🙆🏽", "🙆🏾", "🙆🏿", "🙆‍♂️", "🙆🏻‍♂️",
    "🙆🏼‍♂️", "🙆🏽‍♂️", "🙆🏾‍♂️", "🙆🏿‍♂️",
    "🙆‍♀️", "🙆🏻‍♀️", "🙆🏼‍♀️", "🙆🏽‍♀️",
    "🙆🏾‍♀️", "🙆🏿‍♀️", "💁", "💁🏻", "💁🏼", "💁🏽", "💁🏾", "💁🏿",
    "💁‍♂️", "💁🏻‍♂️", "💁🏼‍♂️", "💁🏽‍♂️",
    "💁🏾‍♂️", "💁🏿‍♂️", "💁‍♀️", "💁🏻‍♀️",
    "💁🏼‍♀️", "💁🏽‍♀️", "💁🏾‍♀️", "💁🏿‍♀️", "🙋",
    "🙋🏻", "🙋🏼", "🙋🏽", "🙋🏾", "🙋🏿", "🙋‍♂️", "🙋🏻‍♂️",
    "🙋🏼‍♂️", "🙋🏽‍♂️", "🙋🏾‍♂️", "🙋🏿‍♂️",
    "🙋‍♀️", "🙋🏻‍♀️", "🙋🏼‍♀️", "🙋🏽‍♀️",
    "🙋🏾‍♀️", "🙋🏿‍♀️", "🧏", "🧏🏻", "🧏🏼", "🧏🏽", "🧏🏾", "🧏🏿",
    "🧏‍♂️", "🧏🏻‍♂️", "🧏🏼‍♂️", "🧏🏽‍♂️",
    "🧏🏾‍♂️", "🧏🏿‍♂️", "🧏‍♀️", "🧏🏻‍♀️",
    "🧏🏼‍♀️", "🧏🏽‍♀️", "🧏🏾‍♀️", "🧏🏿‍♀️", "🙇",
    "🙇🏻", "🙇🏼", "🙇🏽", "🙇🏾", "🙇🏿", "🙇‍♂️", "🙇🏻‍♂️",
    "🙇🏼‍♂️", "🙇🏽‍♂️", "🙇🏾‍♂️", "🙇🏿‍♂️",
    "🙇‍♀️", "🙇🏻‍♀️", "🙇🏼‍♀️", "🙇🏽‍♀️",
    "🙇🏾‍♀️", "🙇🏿‍♀️", "🤦", "🤦🏻", "🤦🏼", "🤦🏽", "🤦🏾", "🤦🏿",
    "🤦‍♂️", "🤦🏻‍♂️", "🤦🏼‍♂️", "🤦🏽‍♂️",
    "🤦🏾‍♂️", "🤦🏿‍♂️", "🤦‍♀️", "🤦🏻‍♀️",
    "🤦🏼‍♀️", "🤦🏽‍♀️", "🤦🏾‍♀️", "🤦🏿‍♀️", "🤷",
    "🤷🏻", "🤷🏼", "🤷🏽", "🤷🏾", "🤷🏿", "🤷‍♂️", "🤷🏻‍♂️",
    "🤷🏼‍♂️", "🤷🏽‍♂️", "🤷🏾‍♂️", "🤷🏿‍♂️",
    "🤷‍♀️", "🤷🏻‍♀️", "🤷🏼‍♀️", "🤷🏽‍♀️",
    "🤷🏾‍♀️", "🤷🏿‍♀️", "🧑‍⚕️", "🧑🏻‍⚕️",
    "🧑🏼‍⚕️", "🧑🏽‍⚕️", "🧑🏾‍⚕️", "🧑🏿‍⚕️",
    "👨‍⚕️", "👨🏻‍⚕️", "👨🏼‍⚕️", "👨🏽‍⚕️",
    "👨🏾‍⚕️", "👨🏿‍⚕️", "👩‍⚕️", "👩🏻‍⚕️",
    "👩🏼‍⚕️", "👩🏽‍⚕️", "👩🏾‍⚕️", "👩🏿‍⚕️",
    "🧑‍🎓", "🧑🏻‍🎓", "🧑🏼‍🎓", "🧑🏽‍🎓", "🧑🏾‍🎓",
    "🧑🏿‍🎓", "👨‍🎓", "👨🏻‍🎓", "👨🏼‍🎓", "👨🏽‍🎓",
    "👨🏾‍🎓", "👨🏿‍🎓", "👩‍🎓", "👩🏻‍🎓", "👩🏼‍🎓",
    "👩🏽‍🎓", "👩🏾‍🎓", "👩🏿‍🎓", "🧑‍🏫", "🧑🏻‍🏫",
    "🧑🏼‍🏫", "🧑🏽‍🏫", "🧑🏾‍🏫", "🧑🏿‍🏫", "👨‍🏫",
    "👨🏻‍🏫", "👨🏼‍🏫", "👨🏽‍🏫", "👨🏾‍🏫", "👨🏿‍🏫",
    "👩‍🏫", "👩🏻‍🏫", "👩🏼‍🏫", "👩🏽‍🏫", "👩🏾‍🏫",
    "👩🏿‍🏫", "🧑‍⚖️", "🧑🏻‍⚖️", "🧑🏼‍⚖️",
    "🧑🏽‍⚖️", "🧑🏾‍⚖️", "🧑🏿‍⚖️", "👨‍⚖️",
    "👨🏻‍⚖️", "👨🏼‍⚖️", "👨🏽‍⚖️", "👨🏾‍⚖️",
    "👨🏿‍⚖️", "👩‍⚖️", "👩🏻‍⚖️", "👩🏼‍⚖️",
    "👩🏽‍⚖️", "👩🏾‍⚖️", "👩🏿‍⚖️", "🧑‍🌾", "🧑🏻‍🌾",
    "🧑🏼‍🌾", "🧑🏽‍🌾", "🧑🏾‍🌾", "🧑🏿‍🌾", "👨‍🌾",
    "👨🏻‍🌾", "👨🏼‍🌾", "👨🏽‍🌾", "👨🏾‍🌾", "👨🏿‍🌾",
    "👩‍🌾", "👩🏻‍🌾", "👩🏼‍🌾", "👩🏽‍🌾", "👩🏾‍🌾",
    "👩🏿‍🌾", "🧑‍🍳", "🧑🏻‍🍳", "🧑🏼‍🍳", "🧑🏽‍🍳",
    "🧑🏾‍🍳", "🧑🏿‍🍳", "👨‍🍳", "👨🏻‍🍳", "👨🏼‍🍳",
    "👨🏽‍🍳", "👨🏾‍🍳", "👨🏿‍🍳", "👩‍🍳", "👩🏻‍🍳",
    "👩🏼‍🍳", "👩🏽‍🍳", "👩🏾‍🍳", "👩🏿‍🍳", "🧑‍🔧",
    "🧑🏻‍🔧", "🧑🏼‍🔧", "🧑🏽‍🔧", "🧑🏾‍🔧", "🧑🏿‍🔧",
    "👨‍🔧", "👨🏻‍🔧", "👨🏼‍🔧", "👨🏽‍🔧", "👨🏾‍🔧",
    "👨🏿‍🔧", "👩‍🔧", "👩🏻‍🔧", "👩🏼‍🔧", "👩🏽‍🔧",
    "👩🏾‍🔧", "👩🏿‍🔧", "🧑‍🏭", "🧑🏻‍🏭", "🧑🏼‍🏭",
    "🧑🏽‍🏭", "🧑🏾‍🏭", "🧑🏿‍🏭", "👨‍🏭", "👨🏻‍🏭",
    "👨🏼‍🏭", "👨🏽‍🏭", "👨🏾‍🏭", "👨🏿‍🏭", "👩‍🏭",
    "👩🏻‍🏭", "👩🏼‍🏭", "👩🏽‍🏭", "👩🏾‍🏭", "👩🏿‍🏭",
    "🧑‍💼", "🧑🏻‍💼", "🧑🏼‍💼", "🧑🏽‍💼", "🧑🏾‍💼",
    "🧑🏿‍💼", "👨‍💼", "👨🏻‍💼", "👨🏼‍💼", "👨🏽‍💼",
    "👨🏾‍💼", "👨🏿‍💼", "👩‍💼", "👩🏻‍💼", "👩🏼‍💼",
    "👩🏽‍💼", "👩🏾‍💼", "👩🏿‍💼", "🧑‍🔬", "🧑🏻‍🔬",
    "🧑🏼‍🔬", "🧑🏽‍🔬", "🧑🏾‍🔬", "🧑🏿‍🔬", "👨‍🔬",
    "👨🏻‍🔬", "👨🏼‍🔬", "👨🏽‍🔬", "👨🏾‍🔬", "👨🏿‍🔬",
    "👩‍🔬", "👩🏻‍🔬", "👩🏼‍🔬", "👩🏽‍🔬", "👩🏾‍🔬",
    "👩🏿‍🔬", "🧑‍💻", "🧑🏻‍💻", "🧑🏼‍💻", "🧑🏽‍💻",
    "🧑🏾‍💻", "🧑🏿‍💻", "👨‍💻", "👨🏻‍💻", "👨🏼‍💻",
    "👨🏽‍💻", "👨🏾‍💻", "👨🏿‍💻", "👩‍💻", "👩🏻‍💻",
    "👩🏼‍💻", "👩🏽‍💻", "👩🏾‍💻", "👩🏿‍💻", "🧑‍🎤",
    "🧑🏻‍🎤", "🧑🏼‍🎤", "🧑🏽‍🎤", "🧑🏾‍🎤", "🧑🏿‍🎤",
    "👨‍🎤", "👨🏻‍🎤", "👨🏼‍🎤", "👨🏽‍🎤", "👨🏾‍🎤",
    "👨🏿‍🎤", "👩‍🎤", "👩🏻‍🎤", "👩🏼‍🎤", "👩🏽‍🎤",
    "👩🏾‍🎤", "👩🏿‍🎤", "🧑‍🎨", "🧑🏻‍🎨", "🧑🏼‍🎨",
    "🧑🏽‍🎨", "🧑🏾‍🎨", "🧑🏿‍🎨", "👨‍🎨", "👨🏻‍🎨",
    "👨🏼‍🎨", "👨🏽‍🎨", "👨🏾‍🎨", "👨🏿‍🎨", "👩‍🎨",
    "👩🏻‍🎨", "👩🏼‍🎨", "👩🏽‍🎨", "👩🏾‍🎨", "👩🏿‍🎨",
    "🧑‍✈️", "🧑🏻‍✈️", "🧑🏼‍✈️", "🧑🏽‍✈️",
    "🧑🏾‍✈️", "🧑🏿‍✈️", "👨‍✈️", "👨🏻‍✈️",
    "👨🏼‍✈️", "👨🏽‍✈️", "👨🏾‍✈️", "👨🏿‍✈️",
    "👩‍✈️", "👩🏻‍✈️", "👩🏼‍✈️", "👩🏽‍✈️",
    "👩🏾‍✈️", "👩🏿‍✈️", "🧑‍🚀", "🧑🏻‍🚀", "🧑🏼‍🚀",
    "🧑🏽‍🚀", "🧑🏾‍🚀", "🧑🏿‍🚀", "👨‍🚀", "👨🏻‍🚀",
    "👨🏼‍🚀", "👨🏽‍🚀", "👨🏾‍🚀", "👨🏿‍🚀", "👩‍🚀",
    "👩🏻‍🚀", "👩🏼‍🚀", "👩🏽‍🚀", "👩🏾‍🚀", "👩🏿‍🚀",
    "🧑‍🚒", "🧑🏻‍🚒", "🧑🏼‍🚒", "🧑🏽‍🚒", "🧑🏾‍🚒",
    "🧑🏿‍🚒", "👨‍🚒", "👨🏻‍🚒", "👨🏼‍🚒", "👨🏽‍🚒",
    "👨🏾‍🚒", "👨🏿‍🚒", "👩‍🚒", "👩🏻‍🚒", "👩🏼‍🚒",
    "👩🏽‍🚒", "👩🏾‍🚒", "👩🏿‍🚒", "👮", "👮🏻", "👮🏼", "👮🏽", "👮🏾",
    "👮🏿", "👮‍♂️", "👮🏻‍♂️", "👮🏼‍♂️", "👮🏽‍♂️",
    "👮🏾‍♂️", "👮🏿‍♂️", "👮‍♀️", "👮🏻‍♀️",
    "👮🏼‍♀️", "👮🏽‍♀️", "👮🏾‍♀️", "👮🏿‍♀️", "🕵️",
    "🕵🏻", "🕵🏼", "🕵🏽", "🕵🏾", "🕵🏿", "🕵️‍♂️", "🕵🏻‍♂️",
    "🕵🏼‍♂️", "🕵🏽‍♂️", "🕵🏾‍♂️", "🕵🏿‍♂️",
    "🕵️‍♀️", "🕵🏻‍♀️", "🕵🏼‍♀️", "🕵🏽‍♀️",
    "🕵🏾‍♀️", "🕵🏿‍♀️", "💂", "💂🏻", "💂🏼", "💂🏽", "💂🏾", "💂🏿",
    "💂‍♂️", "💂🏻‍♂️", "💂🏼‍♂️", "💂🏽‍♂️",
    "💂🏾‍♂️", "💂🏿‍♂️", "💂‍♀️", "💂🏻‍♀️",
    "💂🏼‍♀️", "💂🏽‍♀️", "💂🏾‍♀️", "💂🏿‍♀️", "🥷",
    "🥷🏻", "🥷🏼", "🥷🏽", "🥷🏾", "🥷🏿", "👷", "👷🏻", "👷🏼", "👷🏽", "👷🏾", "👷🏿",
    "👷‍♂️", "👷🏻‍♂️", "👷🏼‍♂️", "👷🏽‍♂️",
    "👷🏾‍♂️", "👷🏿‍♂️", "👷‍♀️", "👷🏻‍♀️",
    "👷🏼‍♀️", "👷🏽‍♀️", "👷🏾‍♀️", "👷🏿‍♀️", "🤴",
    "🤴🏻", "🤴🏼", "🤴🏽", "🤴🏾", "🤴🏿", "👸", "👸🏻", "👸🏼", "👸🏽", "👸🏾", "👸🏿", "👳",
    "👳🏻", "👳🏼", "👳🏽", "👳🏾", "👳🏿", "👳‍♂️", "👳🏻‍♂️",
    "👳🏼‍♂️", "👳🏽‍♂️", "👳🏾‍♂️", "👳🏿‍♂️",
    "👳‍♀️", "👳🏻‍♀️", "👳🏼‍♀️", "👳🏽‍♀️",
    "👳🏾‍♀️", "👳🏿‍♀️", "👲", "👲🏻", "👲🏼", "👲🏽", "👲🏾", "👲🏿", "🧕",
    "🧕🏻", "🧕🏼", "🧕🏽", "🧕🏾", "🧕🏿", "🤵", "🤵🏻", "🤵🏼", "🤵🏽", "🤵🏾", "🤵🏿",
    "🤵‍♂️", "🤵🏻‍♂️", "🤵🏼‍♂️", "🤵🏽‍♂️",
    "🤵🏾‍♂️", "🤵🏿‍♂️", "🤵‍♀️", "🤵🏻‍♀️",
    "🤵🏼‍♀️", "🤵🏽‍♀️", "🤵🏾‍♀️", "🤵🏿‍♀️", "👰",
    "👰🏻", "👰🏼", "👰🏽", "👰🏾", "👰🏿", "👰‍♂️", "👰🏻‍♂️",
    "👰🏼‍♂️", "👰🏽‍♂️", "👰🏾‍♂️", "👰🏿‍♂️",
    "👰‍♀️", "👰🏻‍♀️", "👰🏼‍♀️", "👰🏽‍♀️",
    "👰🏾‍♀️", "👰🏿‍♀️", "🤰", "🤰🏻", "🤰🏼", "🤰🏽", "🤰🏾", "🤰🏿", "🤱",
    "🤱🏻", "🤱🏼", "🤱🏽", "🤱🏾", "🤱🏿", "👩‍🍼", "👩🏻‍🍼", "👩🏼‍🍼",
    "👩🏽‍🍼", "👩🏾‍🍼", "👩🏿‍🍼", "👨‍🍼", "👨🏻‍🍼",
    "👨🏼‍🍼", "👨🏽‍🍼", "👨🏾‍🍼", "👨🏿‍🍼", "🧑‍🍼",
    "🧑🏻‍🍼", "🧑🏼‍🍼", "🧑🏽‍🍼", "🧑🏾‍🍼", "🧑🏿‍🍼",
    "👼", "👼🏻", "👼🏼", "👼🏽", "👼🏾", "👼🏿", "🎅", "🎅🏻", "🎅🏼", "🎅🏽", "🎅🏾", "🎅🏿",
    "🤶", "🤶🏻", "🤶🏼", "🤶🏽", "🤶🏾", "🤶🏿", "🧑‍🎄", "🧑🏻‍🎄",
    "🧑🏼‍🎄", "🧑🏽‍🎄", "🧑🏾‍🎄", "🧑🏿‍🎄", "🦸", "🦸🏻",
    "🦸🏼", "🦸🏽", "🦸🏾", "🦸🏿", "🦸‍♂️", "🦸🏻‍♂️", "🦸🏼‍♂️",
    "🦸🏽‍♂️", "🦸🏾‍♂️", "🦸🏿‍♂️", "🦸‍♀️",
    "🦸🏻‍♀️", "🦸🏼‍♀️", "🦸🏽‍♀️", "🦸🏾‍♀️",
    "🦸🏿‍♀️", "🦹", "🦹🏻", "🦹🏼", "🦹🏽", "🦹🏾", "🦹🏿", "🦹‍♂️",
    "🦹🏻‍♂️", "🦹🏼‍♂️", "🦹🏽‍♂️", "🦹🏾‍♂️",
    "🦹🏿‍♂️", "🦹‍♀️", "🦹🏻‍♀️", "🦹🏼‍♀️",
    "🦹🏽‍♀️", "🦹🏾‍♀️", "🦹🏿‍♀️", "🧙", "🧙🏻", "🧙🏼", "🧙🏽",
    "🧙🏾", "🧙🏿", "🧙‍♂️", "🧙🏻‍♂️", "🧙🏼‍♂️", "🧙🏽‍♂️",
    "🧙🏾‍♂️", "🧙🏿‍♂️", "🧙‍♀️", "🧙🏻‍♀️",
    "🧙🏼‍♀️", "🧙🏽‍♀️", "🧙🏾‍♀️", "🧙🏿‍♀️", "🧚",
    "🧚🏻", "🧚🏼", "🧚🏽", "🧚🏾", "🧚🏿", "🧚‍♂️", "🧚🏻‍♂️",
    "🧚🏼‍♂️", "🧚🏽‍♂️", "🧚🏾‍♂️", "🧚🏿‍♂️",
    "🧚‍♀️", "🧚🏻‍♀️", "🧚🏼‍♀️", "🧚🏽‍♀️",
    "🧚🏾‍♀️", "🧚🏿‍♀️", "🧛", "🧛🏻", "🧛🏼", "🧛🏽", "🧛🏾", "🧛🏿",
    "🧛‍♂️", "🧛🏻‍♂️", "🧛🏼‍♂️", "🧛🏽‍♂️",
    "🧛🏾‍♂️", "🧛🏿‍♂️", "🧛‍♀️", "🧛🏻‍♀️",
    "🧛🏼‍♀️", "🧛🏽‍♀️", "🧛🏾‍♀️", "🧛🏿‍♀️", "🧜",
    "🧜🏻", "🧜🏼", "🧜🏽", "🧜🏾", "🧜🏿", "🧜‍♂️", "🧜🏻‍♂️",
    "🧜🏼‍♂️", "🧜🏽‍♂️", "🧜🏾‍♂️", "🧜🏿‍♂️",
    "🧜‍♀️", "🧜🏻‍♀️", "🧜🏼‍♀️", "🧜🏽‍♀️",
    "🧜🏾‍♀️", "🧜🏿‍♀️", "🧝", "🧝🏻", "🧝🏼", "🧝🏽", "🧝🏾", "🧝🏿",
    "🧝‍♂️", "🧝🏻‍♂️", "🧝🏼‍♂️", "🧝🏽‍♂️",
    "🧝🏾‍♂️", "🧝🏿‍♂️", "🧝‍♀️", "🧝🏻‍♀️",
    "🧝🏼‍♀️", "🧝🏽‍♀️", "🧝🏾‍♀️", "🧝🏿‍♀️", "🧞",
    "🧞‍♂️", "🧞‍♀️", "🧟", "🧟‍♂️", "🧟‍♀️", "💆", "💆🏻", "💆🏼",
    "💆🏽", "💆🏾", "💆🏿", "💆‍♂️", "💆🏻‍♂️", "💆🏼‍♂️",
    "💆🏽‍♂️", "💆🏾‍♂️", "💆🏿‍♂️", "💆‍♀️",
    "💆🏻‍♀️", "💆🏼‍♀️", "💆🏽‍♀️", "💆🏾‍♀️",
    "💆🏿‍♀️", "💇", "💇🏻", "💇🏼", "💇🏽", "💇🏾", "💇🏿", "💇‍♂️",
    "💇🏻‍♂️", "💇🏼‍♂️", "💇🏽‍♂️", "💇🏾‍♂️",
    "💇🏿‍♂️", "💇‍♀️", "💇🏻‍♀️", "💇🏼‍♀️",
    "💇🏽‍♀️", "💇🏾‍♀️", "💇🏿‍♀️", "🚶", "🚶🏻", "🚶🏼", "🚶🏽",
    "🚶🏾", "🚶🏿", "🚶‍♂️", "🚶🏻‍♂️", "🚶🏼‍♂️", "🚶🏽‍♂️",
    "🚶🏾‍♂️", "🚶🏿‍♂️", "🚶‍♀️", "🚶🏻‍♀️",
    "🚶🏼‍♀️", "🚶🏽‍♀️", "🚶🏾‍♀️", "🚶🏿‍♀️", "🧍",
    "🧍🏻", "🧍🏼", "🧍🏽", "🧍🏾", "🧍🏿", "🧍‍♂️", "🧍🏻‍♂️",
    "🧍🏼‍♂️", "🧍🏽‍♂️", "🧍🏾‍♂️", "🧍🏿‍♂️",
    "🧍‍♀️", "🧍🏻‍♀️", "🧍🏼‍♀️", "🧍🏽‍♀️",
    "🧍🏾‍♀️", "🧍🏿‍♀️", "🧎", "🧎🏻", "🧎🏼", "🧎🏽", "🧎🏾", "🧎🏿",
    "🧎‍♂️", "🧎🏻‍♂️", "🧎🏼‍♂️", "🧎🏽‍♂️",
    "🧎🏾‍♂️", "🧎🏿‍♂️", "🧎‍♀️", "🧎🏻‍♀️",
    "🧎🏼‍♀️", "🧎🏽‍♀️", "🧎🏾‍♀️", "🧎🏿‍♀️",
    "🧑‍🦯", "🧑🏻‍🦯", "🧑🏼‍🦯", "🧑🏽‍🦯", "🧑🏾‍🦯",
    "🧑🏿‍🦯", "👨‍🦯", "👨🏻‍🦯", "👨🏼‍🦯", "👨🏽‍🦯",
    "👨🏾‍🦯", "👨🏿‍🦯", "👩‍🦯", "👩🏻‍🦯", "👩🏼‍🦯",
    "👩🏽‍🦯", "👩🏾‍🦯", "👩🏿‍🦯", "🧑‍🦼", "🧑🏻‍🦼",
    "🧑🏼‍🦼", "🧑🏽‍🦼", "🧑🏾‍🦼", "🧑🏿‍🦼", "👨‍🦼",
    "👨🏻‍🦼", "👨🏼‍🦼", "👨🏽‍🦼", "👨🏾‍🦼", "👨🏿‍🦼",
    "👩‍🦼", "👩🏻‍🦼", "👩🏼‍🦼", "👩🏽‍🦼", "👩🏾‍🦼",
    "👩🏿‍🦼", "🧑‍🦽", "🧑🏻‍🦽", "🧑🏼‍🦽", "🧑🏽‍🦽",
    "🧑🏾‍🦽", "🧑🏿‍🦽", "👨‍🦽", "👨🏻‍🦽", "👨🏼‍🦽",
    "👨🏽‍🦽", "👨🏾‍🦽", "👨🏿‍🦽", "👩‍🦽", "👩🏻‍🦽",
    "👩🏼‍🦽", "👩🏽‍🦽", "👩🏾‍🦽", "👩🏿‍🦽", "🏃", "🏃🏻",
    "🏃🏼", "🏃🏽", "🏃🏾", "🏃🏿", "🏃‍♂️", "🏃🏻‍♂️", "🏃🏼‍♂️",
    "🏃🏽‍♂️", "🏃🏾‍♂️", "🏃🏿‍♂️", "🏃‍♀️",
    "🏃🏻‍♀️", "🏃🏼‍♀️", "🏃🏽‍♀️", "🏃🏾‍♀️",
    "🏃🏿‍♀️", "💃", "💃🏻", "💃🏼", "💃🏽", "💃🏾", "💃🏿", "🕺", "🕺🏻", "🕺🏼", "🕺🏽",
    "🕺🏾", "🕺🏿", "🕴️", "🕴🏻", "🕴🏼", "🕴🏽", "🕴🏾", "🕴🏿", "👯", "👯‍♂️",
    "👯‍♀️", "🧖", "🧖🏻", "🧖🏼", "🧖🏽", "🧖🏾", "🧖🏿", "🧖‍♂️",
    "🧖🏻‍♂️", "🧖🏼‍♂️", "🧖🏽‍♂️", "🧖🏾‍♂️",
    "🧖🏿‍♂️", "🧖‍♀️", "🧖🏻‍♀️", "🧖🏼‍♀️",
    "🧖🏽‍♀️", "🧖🏾‍♀️", "🧖🏿‍♀️", "🧗", "🧗🏻", "🧗🏼", "🧗🏽",
    "🧗🏾", "🧗🏿", "🧗‍♂️", "🧗🏻‍♂️", "🧗🏼‍♂️", "🧗🏽‍♂️",
    "🧗🏾‍♂️", "🧗🏿‍♂️", "🧗‍♀️", "🧗🏻‍♀️",
    "🧗🏼‍♀️", "🧗🏽‍♀️", "🧗🏾‍♀️", "🧗🏿‍♀️", "🤺", "🏇",
    "🏇🏻", "🏇🏼", "🏇🏽", "🏇🏾", "🏇🏿", "⛷️", "🏂", "🏂🏻", "🏂🏼", "🏂🏽", "🏂🏾", "🏂🏿", "🏌️",
    "🏌🏻", "🏌🏼", "🏌🏽", "🏌🏾", "🏌🏿", "🏌️‍♂️", "🏌🏻‍♂️",
    "🏌🏼‍♂️", "🏌🏽‍♂️", "🏌🏾‍♂️", "🏌🏿‍♂️",
    "🏌️‍♀️", "🏌🏻‍♀️", "🏌🏼‍♀️", "🏌🏽‍♀️",
    "🏌🏾‍♀️", "🏌🏿‍♀️", "🏄", "🏄🏻", "🏄🏼", "🏄🏽", "🏄🏾", "🏄🏿",
    "🏄‍♂️", "🏄🏻‍♂️", "🏄🏼‍♂️", "🏄🏽‍♂️",
    "🏄🏾‍♂️", "🏄🏿‍♂️", "🏄‍♀️", "🏄🏻‍♀️",
    "🏄🏼‍♀️", "🏄🏽‍♀️", "🏄🏾‍♀️", "🏄🏿‍♀️", "🚣",
    "🚣🏻", "🚣🏼", "🚣🏽", "🚣🏾", "🚣🏿", "🚣‍♂️", "🚣🏻‍♂️",
    "🚣🏼‍♂️", "🚣🏽‍♂️", "🚣🏾‍♂️", "🚣🏿‍♂️",
    "🚣‍♀️", "🚣🏻‍♀️", "🚣🏼‍♀️", "🚣🏽‍♀️",
    "🚣🏾‍♀️", "🚣🏿‍♀️", "🏊", "🏊🏻", "🏊🏼", "🏊🏽", "🏊🏾", "🏊🏿",
    "🏊‍♂️", "🏊🏻‍♂️", "🏊🏼‍♂️", "🏊🏽‍♂️",
    "🏊🏾‍♂️", "🏊🏿‍♂️", "🏊‍♀️", "🏊🏻‍♀️",
    "🏊🏼‍♀️", "🏊🏽‍♀️", "🏊🏾‍♀️", "🏊🏿‍♀️", "⛹️", "⛹🏻",
    "⛹🏼", "⛹🏽", "⛹🏾", "⛹🏿", "⛹️‍♂️", "⛹🏻‍♂️", "⛹🏼‍♂️",
    "⛹🏽‍♂️", "⛹🏾‍♂️", "⛹🏿‍♂️", "⛹️‍♀️",
    "⛹🏻‍♀️", "⛹🏼‍♀️", "⛹🏽‍♀️", "⛹🏾‍♀️",
    "⛹🏿‍♀️", "🏋️", "🏋🏻", "🏋🏼", "🏋🏽", "🏋🏾", "🏋🏿", "🏋️‍♂️",
    "🏋🏻‍♂️", "🏋🏼‍♂️", "🏋🏽‍♂️", "🏋🏾‍♂️",
    "🏋🏿‍♂️", "🏋️‍♀️", "🏋🏻‍♀️", "🏋🏼‍♀️",
    "🏋🏽‍♀️", "🏋🏾‍♀️", "🏋🏿‍♀️", "🚴", "🚴🏻", "🚴🏼", "🚴🏽",
    "🚴🏾", "🚴🏿", "🚴‍♂️", "🚴🏻‍♂️", "🚴🏼‍♂️", "🚴🏽‍♂️",
    "🚴🏾‍♂️", "🚴🏿‍♂️", "🚴‍♀️", "🚴🏻‍♀️",
    "🚴🏼‍♀️", "🚴🏽‍♀️", "🚴🏾‍♀️", "🚴🏿‍♀️", "🚵",
    "🚵🏻", "🚵🏼", "🚵🏽", "🚵🏾", "🚵🏿", "🚵‍♂️", "🚵🏻‍♂️",
    "🚵🏼‍♂️", "🚵🏽‍♂️", "🚵🏾‍♂️", "🚵🏿‍♂️",
    "🚵‍♀️", "🚵🏻‍♀️", "🚵🏼‍♀️", "🚵🏽‍♀️",
    "🚵🏾‍♀️", "🚵🏿‍♀️", "🤸", "🤸🏻", "🤸🏼", "🤸🏽", "🤸🏾", "🤸🏿",
    "🤸‍♂️", "🤸🏻‍♂️", "🤸🏼‍♂️", "🤸🏽‍♂️",
    "🤸🏾‍♂️", "🤸🏿‍♂️", "🤸‍♀️", "🤸🏻‍♀️",
    "🤸🏼‍♀️", "🤸🏽‍♀️", "🤸🏾‍♀️", "🤸🏿‍♀️", "🤼",
    "🤼‍♂️", "🤼‍♀️", "🤽", "🤽🏻", "🤽🏼", "🤽🏽", "🤽🏾", "🤽🏿", "🤽‍♂️",
    "🤽🏻‍♂️", "🤽🏼‍♂️", "🤽🏽‍♂️", "🤽🏾‍♂️",
    "🤽🏿‍♂️", "🤽‍♀️", "🤽🏻‍♀️", "🤽🏼‍♀️",
    "🤽🏽‍♀️", "🤽🏾‍♀️", "🤽🏿‍♀️", "🤾", "🤾🏻", "🤾🏼", "🤾🏽",
    "🤾🏾", "🤾🏿", "🤾‍♂️", "🤾🏻‍♂️", "🤾🏼‍♂️", "🤾🏽‍♂️",
    "🤾🏾‍♂️", "🤾🏿‍♂️", "🤾‍♀️", "🤾🏻‍♀️",
    "🤾🏼‍♀️", "🤾🏽‍♀️", "🤾🏾‍♀️", "🤾🏿‍♀️", "🤹",
    "🤹🏻", "🤹🏼", "🤹🏽", "🤹🏾", "🤹🏿", "🤹‍♂️", "🤹🏻‍♂️",
    "🤹🏼‍♂️", "🤹🏽‍♂️", "🤹🏾‍♂️", "🤹🏿‍♂️",
    "🤹‍♀️", "🤹🏻‍♀️", "🤹🏼‍♀️", "🤹🏽‍♀️",
    "🤹🏾‍♀️", "🤹🏿‍♀️", "🧘", "🧘🏻", "🧘🏼", "🧘🏽", "🧘🏾", "🧘🏿",
    "🧘‍♂️", "🧘🏻‍♂️", "🧘🏼‍♂️", "🧘🏽‍♂️",
    "🧘🏾‍♂️", "🧘🏿‍♂️", "🧘‍♀️", "🧘🏻‍♀️",
    "🧘🏼‍♀️", "🧘🏽‍♀️", "🧘🏾‍♀️", "🧘🏿‍♀️", "🛀",
    "🛀🏻", "🛀🏼", "🛀🏽", "🛀🏾", "🛀🏿", "🛌", "🛌🏻", "🛌🏼", "🛌🏽", "🛌🏾", "🛌🏿",
    "🧑‍🤝‍🧑", "🧑🏻‍🤝‍🧑🏻", "🧑🏻‍🤝‍🧑🏼",
    "🧑🏻‍🤝‍🧑🏽", "🧑🏻‍🤝‍🧑🏾", "🧑🏻‍🤝‍🧑🏿",
    "🧑🏼‍🤝‍🧑🏻", "🧑🏼‍🤝‍🧑🏼", "🧑🏼‍🤝‍🧑🏽",
    "🧑🏼‍🤝‍🧑🏾", "🧑🏼‍🤝‍🧑🏿", "🧑🏽‍🤝‍🧑🏻",
    "🧑🏽‍🤝‍🧑🏼", "🧑🏽‍🤝‍🧑🏽", "🧑🏽‍🤝‍🧑🏾",
    "🧑🏽‍🤝‍🧑🏿", "🧑🏾‍🤝‍🧑🏻", "🧑🏾‍🤝‍🧑🏼",
    "🧑🏾‍🤝‍🧑🏽", "🧑🏾‍🤝‍🧑🏾", "🧑🏾‍🤝‍🧑🏿",
    "🧑🏿‍🤝‍🧑🏻", "🧑🏿‍🤝‍🧑🏼", "🧑🏿‍🤝‍🧑🏽",
    "🧑🏿‍🤝‍🧑🏾", "🧑🏿‍🤝‍🧑🏿", "👭", "👭🏻",
    "👩🏻‍🤝‍👩🏼", "👩🏻‍🤝‍👩🏽", "👩🏻‍🤝‍👩🏾",
    "👩🏻‍🤝‍👩🏿", "👩🏼‍🤝‍👩🏻", "👭🏼",
    "👩🏼‍🤝‍👩🏽", "👩🏼‍🤝‍👩🏾", "👩🏼‍🤝‍👩🏿",
    "👩🏽‍🤝‍👩🏻", "👩🏽‍🤝‍👩🏼", "👭🏽",
    "👩🏽‍🤝‍👩🏾", "👩🏽‍🤝‍👩🏿", "👩🏾‍🤝‍👩🏻",
    "👩🏾‍🤝‍👩🏼", "👩🏾‍🤝‍👩🏽", "👭🏾",
    "👩🏾‍🤝‍👩🏿", "👩🏿‍🤝‍👩🏻", "👩🏿‍🤝‍👩🏼",
    "👩🏿‍🤝‍👩🏽", "👩🏿‍🤝‍👩🏾", "👭🏿", "👫", "👫🏻",
    "👩🏻‍🤝‍👨🏼", "👩🏻‍🤝‍👨🏽", "👩🏻‍🤝‍👨🏾",
    "👩🏻‍🤝‍👨🏿", "👩🏼‍🤝‍👨🏻", "👫🏼",
    "👩🏼‍🤝‍👨🏽", "👩🏼‍🤝‍👨🏾", "👩🏼‍🤝‍👨🏿",
    "👩🏽‍🤝‍👨🏻", "👩🏽‍🤝‍👨🏼", "👫🏽",
    "👩🏽‍🤝‍👨🏾", "👩🏽‍🤝‍👨🏿", "👩🏾‍🤝‍👨🏻",
    "👩🏾‍🤝‍👨🏼", "👩🏾‍🤝‍👨🏽", "👫🏾",
    "👩🏾‍🤝‍👨🏿", "👩🏿‍🤝‍👨🏻", "👩🏿‍🤝‍👨🏼",
    "👩🏿‍🤝‍👨🏽", "👩🏿‍🤝‍👨🏾", "👫🏿", "👬", "👬🏻",
    "👨🏻‍🤝‍👨🏼", "👨🏻‍🤝‍👨🏽", "👨🏻‍🤝‍👨🏾",
    "👨🏻‍🤝‍👨🏿", "👨🏼‍🤝‍👨🏻", "👬🏼",
    "👨🏼‍🤝‍👨🏽", "👨🏼‍🤝‍👨🏾", "👨🏼‍🤝‍👨🏿",
    "👨🏽‍🤝‍👨🏻", "👨🏽‍🤝‍👨🏼", "👬🏽",
    "👨🏽‍🤝‍👨🏾", "👨🏽‍🤝‍👨🏿", "👨🏾‍🤝‍👨🏻",
    "👨🏾‍🤝‍👨🏼", "👨🏾‍🤝‍👨🏽", "👬🏾",
    "👨🏾‍🤝‍👨🏿", "👨🏿‍🤝‍👨🏻", "👨🏿‍🤝‍👨🏼",
    "👨🏿‍🤝‍👨🏽", "👨🏿‍🤝‍👨🏾", "👬🏿", "💏", "💏🏻", "💏🏼",
    "💏🏽", "💏🏾", "💏🏿", "🧑🏻‍❤️‍💋‍🧑🏼",
    "🧑🏻‍❤️‍💋‍🧑🏽", "🧑🏻‍❤️‍💋‍🧑🏾",
    "🧑🏻‍❤️‍💋‍🧑🏿", "🧑🏼‍❤️‍💋‍🧑🏻",
    "🧑🏼‍❤️‍💋‍🧑🏽", "🧑🏼‍❤️‍💋‍🧑🏾",
    "🧑🏼‍❤️‍💋‍🧑🏿", "🧑🏽‍❤️‍💋‍🧑🏻",
    "🧑🏽‍❤️‍💋‍🧑🏼", "🧑🏽‍❤️‍💋‍🧑🏾",
    "🧑🏽‍❤️‍💋‍🧑🏿", "🧑🏾‍❤️‍💋‍🧑🏻",
    "🧑🏾‍❤️‍💋‍🧑🏼", "🧑🏾‍❤️‍💋‍🧑🏽",
    "🧑🏾‍❤️‍💋‍🧑🏿", "🧑🏿‍❤️‍💋‍🧑🏻",
    "🧑🏿‍❤️‍💋‍🧑🏼", "🧑🏿‍❤️‍💋‍🧑🏽",
    "🧑🏿‍❤️‍💋‍🧑🏾", "👩‍❤️‍💋‍👨",
    "👩🏻‍❤️‍💋‍👨🏻", "👩🏻‍❤️‍💋‍👨🏼",
    "👩🏻‍❤️‍💋‍👨🏽", "👩🏻‍❤️‍💋‍👨🏾",
    "👩🏻‍❤️‍💋‍👨🏿", "👩🏼‍❤️‍💋‍👨🏻",
    "👩🏼‍❤️‍💋‍👨🏼", "👩🏼‍❤️‍💋‍👨🏽",
    "👩🏼‍❤️‍💋‍👨🏾", "👩🏼‍❤️‍💋‍👨🏿",
    "👩🏽‍❤️‍💋‍👨🏻", "👩🏽‍❤️‍💋‍👨🏼",
    "👩🏽‍❤️‍💋‍👨🏽", "👩🏽‍❤️‍💋‍👨🏾",
    "👩🏽‍❤️‍💋‍👨🏿", "👩🏾‍❤️‍💋‍👨🏻",
    "👩🏾‍❤️‍💋‍👨🏼", "👩🏾‍❤️‍💋‍👨🏽",
    "👩🏾‍❤️‍💋‍👨🏾", "👩🏾‍❤️‍💋‍👨🏿",
    "👩🏿‍❤️‍💋‍👨🏻", "👩🏿‍❤️‍💋‍👨🏼",
    "👩🏿‍❤️‍💋‍👨🏽", "👩🏿‍❤️‍💋‍👨🏾",
    "👩🏿‍❤️‍💋‍👨🏿", "👨‍❤️‍💋‍👨",
    "👨🏻‍❤️‍💋‍👨🏻", "👨🏻‍❤️‍💋‍👨🏼",
    "👨🏻‍❤️‍💋‍👨🏽", "👨🏻‍❤️‍💋‍👨🏾",
    "👨🏻‍❤️‍💋‍👨🏿", "👨🏼‍❤️‍💋‍👨🏻",
    "👨🏼‍❤️‍💋‍👨🏼", "👨🏼‍❤️‍💋‍👨🏽",
    "👨🏼‍❤️‍💋‍👨🏾", "👨🏼‍❤️‍💋‍👨🏿",
    "👨🏽‍❤️‍💋‍👨🏻", "👨🏽‍❤️‍💋‍👨🏼",
    "👨🏽‍❤️‍💋‍👨🏽", "👨🏽‍❤️‍💋‍👨🏾",
    "👨🏽‍❤️‍💋‍👨🏿", "👨🏾‍❤️‍💋‍👨🏻",
    "👨🏾‍❤️‍💋‍👨🏼", "👨🏾‍❤️‍💋‍👨🏽",
    "👨🏾‍❤️‍💋‍👨🏾", "👨🏾‍❤️‍💋‍👨🏿",
    "👨🏿‍❤️‍💋‍👨🏻", "👨🏿‍❤️‍💋‍👨🏼",
    "👨🏿‍❤️‍💋‍👨🏽", "👨🏿‍❤️‍💋‍👨🏾",
    "👨🏿‍❤️‍💋‍👨🏿", "👩‍❤️‍💋‍👩",
    "👩🏻‍❤️‍💋‍👩🏻", "👩🏻‍❤️‍💋‍👩🏼",
    "👩🏻‍❤️‍💋‍👩🏽", "👩🏻‍❤️‍💋‍👩🏾",
    "👩🏻‍❤️‍💋‍👩🏿", "👩🏼‍❤️‍💋‍👩🏻",
    "👩🏼‍❤️‍💋‍👩🏼", "👩🏼‍❤️‍💋‍👩🏽",
    "👩🏼‍❤️‍💋‍👩🏾", "👩🏼‍❤️‍💋‍👩🏿",
    "👩🏽‍❤️‍💋‍👩🏻", "👩🏽‍❤️‍💋‍👩🏼",
    "👩🏽‍❤️‍💋‍👩🏽", "👩🏽‍❤️‍💋‍👩🏾",
    "👩🏽‍❤️‍💋‍👩🏿", "👩🏾‍❤️‍💋‍👩🏻",
    "👩🏾‍❤️‍💋‍👩🏼", "👩🏾‍❤️‍💋‍👩🏽",
    "👩🏾‍❤️‍💋‍👩🏾", "👩🏾‍❤️‍💋‍👩🏿",
    "👩🏿‍❤️‍💋‍👩🏻", "👩🏿‍❤️‍💋‍👩🏼",
    "👩🏿‍❤️‍💋‍👩🏽", "👩🏿‍❤️‍💋‍👩🏾",
    "👩🏿‍❤️‍💋‍👩🏿", "💑", "💑🏻", "💑🏼", "💑🏽", "💑🏾", "💑🏿",
    "🧑🏻‍❤️‍🧑🏼", "🧑🏻‍❤️‍🧑🏽", "🧑🏻‍❤️‍🧑🏾",
    "🧑🏻‍❤️‍🧑🏿", "🧑🏼‍❤️‍🧑🏻", "🧑🏼‍❤️‍🧑🏽",
    "🧑🏼‍❤️‍🧑🏾", "🧑🏼‍❤️‍🧑🏿", "🧑🏽‍❤️‍🧑🏻",
    "🧑🏽‍❤️‍🧑🏼", "🧑🏽‍❤️‍🧑🏾", "🧑🏽‍❤️‍🧑🏿",
    "🧑🏾‍❤️‍🧑🏻", "🧑🏾‍❤️‍🧑🏼", "🧑🏾‍❤️‍🧑🏽",
    "🧑🏾‍❤️‍🧑🏿", "🧑🏿‍❤️‍🧑🏻", "🧑🏿‍❤️‍🧑🏼",
    "🧑🏿‍❤️‍🧑🏽", "🧑🏿‍❤️‍🧑🏾", "👩‍❤️‍👨",
    "👩🏻‍❤️‍👨🏻", "👩🏻‍❤️‍👨🏼", "👩🏻‍❤️‍👨🏽",
    "👩🏻‍❤️‍👨🏾", "👩🏻‍❤️‍👨🏿", "👩🏼‍❤️‍👨🏻",
    "👩🏼‍❤️‍👨🏼", "👩🏼‍❤️‍👨🏽", "👩🏼‍❤️‍👨🏾",
    "👩🏼‍❤️‍👨🏿", "👩🏽‍❤️‍👨🏻", "👩🏽‍❤️‍👨🏼",
    "👩🏽‍❤️‍👨🏽", "👩🏽‍❤️‍👨🏾", "👩🏽‍❤️‍👨🏿",
    "👩🏾‍❤️‍👨🏻", "👩🏾‍❤️‍👨🏼", "👩🏾‍❤️‍👨🏽",
    "👩🏾‍❤️‍👨🏾", "👩🏾‍❤️‍👨🏿", "👩🏿‍❤️‍👨🏻",
    "👩🏿‍❤️‍👨🏼", "👩🏿‍❤️‍👨🏽", "👩🏿‍❤️‍👨🏾",
    "👩🏿‍❤️‍👨🏿", "👨‍❤️‍👨", "👨🏻‍❤️‍👨🏻",
    "👨🏻‍❤️‍👨🏼", "👨🏻‍❤️‍👨🏽", "👨🏻‍❤️‍👨🏾",
    "👨🏻‍❤️‍👨🏿", "👨🏼‍❤️‍👨🏻", "👨🏼‍❤️‍👨🏼",
    "👨🏼‍❤️‍👨🏽", "👨🏼‍❤️‍👨🏾", "👨🏼‍❤️‍👨🏿",
    "👨🏽‍❤️‍👨🏻", "👨🏽‍❤️‍👨🏼", "👨🏽‍❤️‍👨🏽",
    "👨🏽‍❤️‍👨🏾", "👨🏽‍❤️‍👨🏿", "👨🏾‍❤️‍👨🏻",
    "👨🏾‍❤️‍👨🏼", "👨🏾‍❤️‍👨🏽", "👨🏾‍❤️‍👨🏾",
    "👨🏾‍❤️‍👨🏿", "👨🏿‍❤️‍👨🏻", "👨🏿‍❤️‍👨🏼",
    "👨🏿‍❤️‍👨🏽", "👨🏿‍❤️‍👨🏾", "👨🏿‍❤️‍👨🏿",
    "👩‍❤️‍👩", "👩🏻‍❤️‍👩🏻", "👩🏻‍❤️‍👩🏼",
    "👩🏻‍❤️‍👩🏽", "👩🏻‍❤️‍👩🏾", "👩🏻‍❤️‍👩🏿",
    "👩🏼‍❤️‍👩🏻", "👩🏼‍❤️‍👩🏼", "👩🏼‍❤️‍👩🏽",
    "👩🏼‍❤️‍👩🏾", "👩🏼‍❤️‍👩🏿", "👩🏽‍❤️‍👩🏻",
    "👩🏽‍❤️‍👩🏼", "👩🏽‍❤️‍👩🏽", "👩🏽‍❤️‍👩🏾",
    "👩🏽‍❤️‍👩🏿", "👩🏾‍❤️‍👩🏻", "👩🏾‍❤️‍👩🏼",
    "👩🏾‍❤️‍👩🏽", "👩🏾‍❤️‍👩🏾", "👩🏾‍❤️‍👩🏿",
    "👩🏿‍❤️‍👩🏻", "👩🏿‍❤️‍👩🏼", "👩🏿‍❤️‍👩🏽",
    "👩🏿‍❤️‍👩🏾", "👩🏿‍❤️‍👩🏿", "👪", "👨‍👩‍👦",
    "👨‍👩‍👧", "👨‍👩‍👧‍👦", "👨‍👩‍👦‍👦",
    "👨‍👩‍👧‍👧", "👨‍👨‍👦", "👨‍👨‍👧",
    "👨‍👨‍👧‍👦", "👨‍👨‍👦‍👦", "👨‍👨‍👧‍👧",
    "👩‍👩‍👦", "👩‍👩‍👧", "👩‍👩‍👧‍👦",
    "👩‍👩‍👦‍👦", "👩‍👩‍👧‍👧", "👨‍👦", "👨‍👦‍👦",
    "👨‍👧", "👨‍👧‍👦", "👨‍👧‍👧", "👩‍👦", "👩‍👦‍👦",
    "👩‍👧", "👩‍👧‍👦", "👩‍👧‍👧", "🗣️", "👤", "👥", "🫂", "👣" };

const std::array<std::string_view, 140> nature_emojis = { "🐵", "🐒", "🦍", "🦧", "🐶", "🐕", "🦮",
    "🐕‍🦺", "🐩", "🐺", "🦊", "🦝", "🐱", "🐈", "🐈‍⬛", "🦁", "🐯", "🐅", "🐆", "🐴",
    "🐎", "🦄", "🦓", "🦌", "🦬", "🐮", "🐂", "🐃", "🐄", "🐷", "🐖", "🐗", "🐽", "🐏", "🐑", "🐐",
    "🐪", "🐫", "🦙", "🦒", "🐘", "🦣", "🦏", "🦛", "🐭", "🐁", "🐀", "🐹", "🐰", "🐇", "🐿️", "🦫",
    "🦔", "🦇", "🐻", "🐻‍❄️", "🐨", "🐼", "🦥", "🦦", "🦨", "🦘", "🦡", "🐾", "🦃", "🐔",
    "🐓", "🐣", "🐤", "🐥", "🐦", "🐧", "🕊️", "🦅", "🦆", "🦢", "🦉", "🦤", "🪶", "🦩", "🦚", "🦜",
    "🐸", "🐊", "🐢", "🦎", "🐍", "🐲", "🐉", "🦕", "🦖", "🐳", "🐋", "🐬", "🦭", "🐟", "🐠", "🐡",
    "🦈", "🐙", "🐚", "🐌", "🦋", "🐛", "🐜", "🐝", "🪲", "🐞", "🦗", "🪳", "🕷️", "🕸️", "🦂", "🦟",
    "🪰", "🪱", "🦠", "💐", "🌸", "💮", "🏵️", "🌹", "🥀", "🌺", "🌻", "🌼", "🌷", "🌱", "🪴", "🌲",
    "🌳", "🌴", "🌵", "🌾", "🌿", "☘️", "🍀", "🍁", "🍂", "🍃" };

const std::array<std::string_view, 129> food_emojis = { "🍇", "🍈", "🍉", "🍊", "🍋", "🍌", "🍍",
    "🥭", "🍎", "🍏", "🍐", "🍑", "🍒", "🍓", "🫐", "🥝", "🍅", "🫒", "🥥", "🥑", "🍆", "🥔", "🥕",
    "🌽", "🌶️", "🫑", "🥒", "🥬", "🥦", "🧄", "🧅", "🍄", "🥜", "🌰", "🍞", "🥐", "🥖", "🫓", "🥨",
    "🥯", "🥞", "🧇", "🧀", "🍖", "🍗", "🥩", "🥓", "🍔", "🍟", "🍕", "🌭", "🥪", "🌮", "🌯", "🫔",
    "🥙", "🧆", "🥚", "🍳", "🥘", "🍲", "🫕", "🥣", "🥗", "🍿", "🧈", "🧂", "🥫", "🍱", "🍘", "🍙",
    "🍚", "🍛", "🍜", "🍝", "🍠", "🍢", "🍣", "🍤", "🍥", "🥮", "🍡", "🥟", "🥠", "🥡", "🦀", "🦞",
    "🦐", "🦑", "🦪", "🍦", "🍧", "🍨", "🍩", "🍪", "🎂", "🍰", "🧁", "🥧", "🍫", "🍬", "🍭", "🍮",
    "🍯", "🍼", "🥛", "☕", "🫖", "🍵", "🍶", "🍾", "🍷", "🍸", "🍹", "🍺", "🍻", "🥂", "🥃", "🥤",
    "🧋", "🧃", "🧉", "🧊", "🥢", "🍽️", "🍴", "🥄", "🔪", "🏺" };

const std::array<std::string_view, 215> travel_emojis = { "🌍", "🌎", "🌏", "🌐", "🗺️", "🗾", "🧭",
    "🏔️", "⛰️", "🌋", "🗻", "🏕️", "🏖️", "🏜️", "🏝️", "🏞️", "🏟️", "🏛️", "🏗️", "🧱", "🪨", "🪵", "🛖",
    "🏘️", "🏚️", "🏠", "🏡", "🏢", "🏣", "🏤", "🏥", "🏦", "🏨", "🏩", "🏪", "🏫", "🏬", "🏭", "🏯",
    "🏰", "💒", "🗼", "🗽", "⛪", "🕌", "🛕", "🕍", "⛩️", "🕋", "⛲", "⛺", "🌁", "🌃", "🏙️", "🌄",
    "🌅", "🌆", "🌇", "🌉", "♨️", "🎠", "🎡", "🎢", "💈", "🎪", "🚂", "🚃", "🚄", "🚅", "🚆", "🚇",
    "🚈", "🚉", "🚊", "🚝", "🚞", "🚋", "🚌", "🚍", "🚎", "🚐", "🚑", "🚒", "🚓", "🚔", "🚕", "🚖",
    "🚗", "🚘", "🚙", "🛻", "🚚", "🚛", "🚜", "🏎️", "🏍️", "🛵", "🦽", "🦼", "🛺", "🚲", "🛴", "🛹",
    "🛼", "🚏", "🛣️", "🛤️", "🛢️", "⛽", "🚨", "🚥", "🚦", "🛑", "🚧", "⚓", "⛵", "🛶", "🚤", "🛳️", "⛴️",
    "🛥️", "🚢", "✈️", "🛩️", "🛫", "🛬", "🪂", "💺", "🚁", "🚟", "🚠", "🚡", "🛰️", "🚀", "🛸", "🛎️", "🧳",
    "⌛", "⏳", "⌚", "⏰", "⏱️", "⏲️", "🕰️", "🕛", "🕧", "🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓",
    "🕟", "🕔", "🕠", "🕕", "🕡", "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🌑",
    "🌒", "🌓", "🌔", "🌕", "🌖", "🌗", "🌘", "🌙", "🌚", "🌛", "🌜", "🌡️", "☀️", "🌝", "🌞", "🪐",
    "⭐", "🌟", "🌠", "🌌", "☁️", "⛅", "⛈️", "🌤️", "🌥️", "🌦️", "🌧️", "🌨️", "🌩️", "🌪️", "🌫️", "🌬️",
    "🌀", "🌈", "🌂", "☂️", "☔", "⛱️", "⚡", "❄️", "☃️", "⛄", "☄️", "🔥", "💧", "🌊" };

const std::array<std::string_view, 84> activity_emojis = { "🎃", "🎄", "🎆", "🎇", "🧨", "✨", "🎈",
    "🎉", "🎊", "🎋", "🎍", "🎎", "🎏", "🎐", "🎑", "🧧", "🎀", "🎁", "🎗️", "🎟️", "🎫", "🎖️", "🏆",
    "🏅", "🥇", "🥈", "🥉", "⚽", "⚾", "🥎", "🏀", "🏐", "🏈", "🏉", "🎾", "🥏", "🎳", "🏏", "🏑",
    "🏒", "🥍", "🏓", "🏸", "🥊", "🥋", "🥅", "⛳", "⛸️", "🎣", "🤿", "🎽", "🎿", "🛷", "🥌", "🎯",
    "🪀", "🪁", "🎱", "🔮", "🪄", "🧿", "🎮", "🕹️", "🎰", "🎲", "🧩", "🧸", "🪅", "🪆", "♠️", "♥️",
    "♦️", "♣️", "♟️", "🃏", "🀄", "🎴", "🎭", "🖼️", "🎨", "🧵", "🪡", "🧶", "🪢" };

const std::array<std::string_view, 250> object_emojis = { "👓", "🕶️", "🥽", "🥼", "🦺", "👔", "👕",
    "👖", "🧣", "🧤", "🧥", "🧦", "👗", "👘", "🥻", "🩱", "🩲", "🩳", "👙", "👚", "👛", "👜", "👝",
    "🛍️", "🎒", "🩴", "👞", "👟", "🥾", "🥿", "👠", "👡", "🩰", "👢", "👑", "👒", "🎩", "🎓", "🧢",
    "🪖", "⛑️", "📿", "💄", "💍", "💎", "🔇", "🔈", "🔉", "🔊", "📢", "📣", "📯", "🔔", "🔕", "🎼",
    "🎵", "🎶", "🎙️", "🎚️", "🎛️", "🎤", "🎧", "📻", "🎷", "🪗", "🎸", "🎹", "🎺", "🎻", "🪕", "🥁",
    "🪘", "📱", "📲", "☎️", "📞", "📟", "📠", "🔋", "🔌", "💻", "🖥️", "🖨️", "⌨️", "🖱️", "🖲️", "💽",
    "💾", "💿", "📀", "🧮", "🎥", "🎞️", "📽️", "🎬", "📺", "📷", "📸", "📹", "📼", "🔍", "🔎", "🕯️",
    "💡", "🔦", "🏮", "🪔", "📔", "📕", "📖", "📗", "📘", "📙", "📚", "📓", "📒", "📃", "📜", "📄",
    "📰", "🗞️", "📑", "🔖", "🏷️", "💰", "🪙", "💴", "💵", "💶", "💷", "💸", "💳", "🧾", "💹", "✉️",
    "📧", "📨", "📩", "📤", "📥", "📦", "📫", "📪", "📬", "📭", "📮", "🗳️", "✏️", "✒️", "🖋️", "🖊️",
    "🖌️", "🖍️", "📝", "💼", "📁", "📂", "🗂️", "📅", "📆", "🗒️", "🗓️", "📇", "📈", "📉", "📊", "📋",
    "📌", "📍", "📎", "🖇️", "📏", "📐", "✂️", "🗃️", "🗄️", "🗑️", "🔒", "🔓", "🔏", "🔐", "🔑", "🗝️",
    "🔨", "🪓", "⛏️", "⚒️", "🛠️", "🗡️", "⚔️", "🔫", "🪃", "🏹", "🛡️", "🪚", "🔧", "🪛", "🔩", "⚙️", "🗜️",
    "⚖️", "🦯", "🔗", "⛓️", "🪝", "🧰", "🧲", "🪜", "⚗️", "🧪", "🧫", "🧬", "🔬", "🔭", "📡", "💉",
    "🩸", "💊", "🩹", "🩺", "🚪", "🛗", "🪞", "🪟", "🛏️", "🛋️", "🪑", "🚽", "🪠", "🚿", "🛁", "🪤",
    "🪒", "🧴", "🧷", "🧹", "🧺", "🧻", "🪣", "🧼", "🪥", "🧽", "🧯", "🛒", "🚬", "⚰️", "🪦", "⚱️",
    "🗿", "🪧" };

const std::array<std::string_view, 220> symbol_emojis = { "🏧", "🚮", "🚰", "♿", "🚹", "🚺", "🚻",
    "🚼", "🚾", "🛂", "🛃", "🛄", "🛅", "⚠️", "🚸", "⛔", "🚫", "🚳", "🚭", "🚯", "🚱", "🚷", "📵",
    "🔞", "☢️", "☣️", "⬆️", "↗️", "➡️", "↘️", "⬇️", "↙️", "⬅️", "↖️", "↕️", "↔️", "↩️", "↪️", "⤴️", "⤵️", "🔃",
    "🔄", "🔙", "🔚", "🔛", "🔜", "🔝", "🛐", "⚛️", "🕉️", "✡️", "☸️", "☯️", "✝️", "☦️", "☪️", "☮️", "🕎",
    "🔯", "♈", "♉", "♊", "♋", "♌", "♍", "♎", "♏", "♐", "♑", "♒", "♓", "⛎", "🔀", "🔁",
    "🔂", "▶️", "⏩", "⏭️", "⏯️", "◀️", "⏪", "⏮️", "🔼", "⏫", "🔽", "⏬", "⏸️", "⏹️", "⏺️", "⏏️", "🎦",
    "🔅", "🔆", "📶", "📳", "📴", "♀️", "♂️", "⚧️", "✖️", "➕", "➖", "➗", "♾️", "‼️", "⁉️", "❓", "❔",
    "❕", "❗", "〰️", "💱", "💲", "⚕️", "♻️", "⚜️", "🔱", "📛", "🔰", "⭕", "✅", "☑️", "✔️", "❌", "❎",
    "➰", "➿", "〽️", "✳️", "✴️", "❇️", "©️", "®️", "™️", "#️⃣", "*️⃣", "0️⃣", "1️⃣", "2️⃣", "3️⃣", "4️⃣", "5️⃣", "6️⃣",
    "7️⃣", "8️⃣", "9️⃣", "🔟", "🔠", "🔡", "🔢", "🔣", "🔤", "🅰️", "🆎", "🅱️", "🆑", "🆒", "🆓", "ℹ️", "🆔",
    "Ⓜ️", "🆕", "🆖", "🅾️", "🆗", "🅿️", "🆘", "🆙", "🆚", "🈁", "🈂️", "🈷️", "🈶", "🈯", "🉐", "🈹",
    "🈚", "🈲", "🉑", "🈸", "🈴", "🈳", "㊗️", "㊙️", "🈺", "🈵", "🔴", "🟠", "🟡", "🟢", "🔵", "🟣",
    "🟤", "⚫", "⚪", "🟥", "🟧", "🟨", "🟩", "🟦", "🟪", "🟫", "⬛", "⬜", "◼️", "◻️", "◾", "◽",
    "▪️", "▫️", "🔶", "🔷", "🔸", "🔹", "🔺", "🔻", "💠", "🔘", "🔳", "🔲" };

const std::array<std::string_view, 266> flag_emojis = { "🏁", "🚩", "🎌", "🏴", "🏳️",
    "🏳️‍🌈", "🏳️‍⚧️", "🏴‍☠️", "🇦🇨", "🇦🇩", "🇦🇪", "🇦🇫", "🇦🇬", "🇦🇮", "🇦🇱",
    "🇦🇲", "🇦🇴", "🇦🇶", "🇦🇷", "🇦🇸", "🇦🇹", "🇦🇺", "🇦🇼", "🇦🇽", "🇦🇿", "🇧🇦", "🇧🇧", "🇧🇩", "🇧🇪", "🇧🇫", "🇧🇬",
    "🇧🇭", "🇧🇮", "🇧🇯", "🇧🇱", "🇧🇲", "🇧🇳", "🇧🇴", "🇧🇶", "🇧🇷", "🇧🇸", "🇧🇹", "🇧🇻", "🇧🇼", "🇧🇾", "🇧🇿", "🇨🇦",
    "🇨🇨", "🇨🇩", "🇨🇫", "🇨🇬", "🇨🇭", "🇨🇮", "🇨🇰", "🇨🇱", "🇨🇲", "🇨🇳", "🇨🇴", "🇨🇵", "🇨🇷", "🇨🇺", "🇨🇻", "🇨🇼",
    "🇨🇽", "🇨🇾", "🇨🇿", "🇩🇪", "🇩🇬", "🇩🇯", "🇩🇰", "🇩🇲", "🇩🇴", "🇩🇿", "🇪🇦", "🇪🇨", "🇪🇪", "🇪🇬", "🇪🇭", "🇪🇷",
    "🇪🇸", "🇪🇹", "🇪🇺", "🇫🇮", "🇫🇯", "🇫🇰", "🇫🇲", "🇫🇴", "🇫🇷", "🇬🇦", "🇬🇧", "🇬🇩", "🇬🇪", "🇬🇫", "🇬🇬", "🇬🇭",
    "🇬🇮", "🇬🇱", "🇬🇲", "🇬🇳", "🇬🇵", "🇬🇶", "🇬🇷", "🇬🇸", "🇬🇹", "🇬🇺", "🇬🇼", "🇬🇾", "🇭🇰", "🇭🇲", "🇭🇳", "🇭🇷",
    "🇭🇹", "🇭🇺", "🇮🇨", "🇮🇩", "🇮🇪", "🇮🇱", "🇮🇲", "🇮🇳", "🇮🇴", "🇮🇶", "🇮🇷", "🇮🇸", "🇮🇹", "🇯🇪", "🇯🇲", "🇯🇴",
    "🇯🇵", "🇰🇪", "🇰🇬", "🇰🇭", "🇰🇮", "🇰🇲", "🇰🇳", "🇰🇵", "🇰🇷", "🇰🇼", "🇰🇾", "🇰🇿", "🇱🇦", "🇱🇧", "🇱🇨", "🇱🇮",
    "🇱🇰", "🇱🇷", "🇱🇸", "🇱🇹", "🇱🇺", "🇱🇻", "🇱🇾", "🇲🇦", "🇲🇨", "🇲🇩", "🇲🇪", "🇲🇫", "🇲🇬", "🇲🇭", "🇲🇰", "🇲🇱",
    "🇲🇲", "🇲🇳", "🇲🇴", "🇲🇵", "🇲🇶", "🇲🇷", "🇲🇸", "🇲🇹", "🇲🇺", "🇲🇻", "🇲🇼", "🇲🇽", "🇲🇾", "🇲🇿", "🇳🇦", "🇳🇨",
    "🇳🇪", "🇳🇫", "🇳🇬", "🇳🇮", "🇳🇱", "🇳🇴", "🇳🇵", "🇳🇷", "🇳🇺", "🇳🇿", "🇴🇲", "🇵🇦", "🇵🇪", "🇵🇫", "🇵🇬", "🇵🇭",
    "🇵🇰", "🇵🇱", "🇵🇲", "🇵🇳", "🇵🇷", "🇵🇸", "🇵🇹", "🇵🇼", "🇵🇾", "🇶🇦", "🇷🇪", "🇷🇴", "🇷🇸", "🇷🇺", "🇷🇼", "🇸🇦",
    "🇸🇧", "🇸🇨", "🇸🇩", "🇸🇪", "🇸🇬", "🇸🇭", "🇸🇮", "🇸🇯", "🇸🇰", "🇸🇱", "🇸🇲", "🇸🇳", "🇸🇴", "🇸🇷", "🇸🇸", "🇸🇹",
    "🇸🇻", "🇸🇽", "🇸🇾", "🇸🇿", "🇹🇦", "🇹🇨", "🇹🇩", "🇹🇫", "🇹🇬", "🇹🇭", "🇹🇯", "🇹🇰", "🇹🇱", "🇹🇲", "🇹🇳", "🇹🇴",
    "🇹🇷", "🇹🇹", "🇹🇻", "🇹🇼", "🇹🇿", "🇺🇦", "🇺🇬", "🇺🇲", "🇺🇳", "🇺🇸", "🇺🇾", "🇺🇿", "🇻🇦", "🇻🇨", "🇻🇪", "🇻🇬",
    "🇻🇮", "🇻🇳", "🇻🇺", "🇼🇫", "🇼🇸", "🇽🇰", "🇾🇪", "🇾🇹", "🇿🇦", "🇿🇲", "🇿🇼" };

const std::array<std::string_view, 45> http_media_types = { "audio/aac", "application/x-abiword",
    "application/x-freearc", "video/x-msvideo", "application/vnd.amazon.ebook",
    "application/octet-stream", "image/bmp", "application/x-bzip", "application/x-bzip2",
    "application/x-csh", "text/css", "text/csv", "application/gzip", "image/gif", "text/html",
    "text/calendar", "application/java-archive", "image/jpeg", "text/javascript",
    "application/json", "audio/mpeg", "video/mpeg", "font/otf", "image/png", "application/pdf",
    "application/rtf", "image/tiff", "video/mp2t", "font/ttf", "text/plain", "audio/wav",
    "audio/webm", "video/webm", "image/webp", "font/woff", "font/woff2", "application/xml",
    "text/xml", "application/vnd.mozilla.xul+xml", "application/zip", "video/3gpp", "audio/3gpp",
    "video/3gpp2", "audio/3gpp2", "application/x-7z-compressed" };

const std::array<std::string_view, 41> http_request_headers
    = { "A-IM", "Accept", "Accept-Charset", "Accept-Datetime", "Accept-Encoding", "Accept-Language",
          "Access-Control-Request-Method", "Access-Control-Request-Headers", "Authorization",
          "Cache-Control", "Connection", "Content-Encoding", "Content-Length", "Content-MD5",
          "Content-Type", "Cookie", "Date", "Expect", "Forwarded", "From", "Host", "HTTP2-Settings",
          "If-Match", "If-Modified-Since", "If-None-Match", "If-Range", "If-Unmodified-Since",
          "Max-Forwards", "Origin", "Pragma", "Prefer", "Proxy-Authorization", "Range", "Referer",
          "TE", "Transfer-Encoding", "User-Agent", "Upgrade", "Upgrade", "Via", "Warning" };

const std::array<std::string_view, 44> http_response_headers = { "Accept-CH",
    "Access-Control-Allow-Origin", "Access-Control-Allow-Credentials",
    "Access-Control-Expose-Headers", "Access-Control-Max-Age", "Access-Control-Allow-Methods",
    "Access-Control-Allow-HeadersAccess-Control-Allow-Origin", "Accept-Patch", "Accept-Ranges",
    "Age", "Allow", "Alt-Svc", "Cache-Control", "Connection", "Content-Disposition",
    "Content-Encoding", "Content-Language", "Content-Length", "Content-Location", "Content-MD5",
    "Content-Range", "Content-Type", "Date", "Delta-Base", "ETag", "Expires", "IM", "Last-Modified",
    "Location", "P3P", "Pragma", "Preference-Applied", "Proxy-Authenticate", "Public-Key-Pins",
    "Retry-After", "Server", "Set-Cookie", "Strict-Transport-Security", "Transfer-Encoding", "Tk",
    "Upgrade", "Vary", "Warning", "WWW-Authenticate" };
}
