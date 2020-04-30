(window.webpackJsonp=window.webpackJsonp||[]).push([[9],{294:function(e,t,n){var content=n(298);"string"==typeof content&&(content=[[e.i,content,""]]),content.locals&&(e.exports=content.locals);(0,n(14).default)("4f4aef1d",content,!0,{sourceMap:!1})},295:function(e,t){e.exports=function(e){e.options.__i18n=e.options.__i18n||[],e.options.__i18n.push('{"ja":{"explanation":"説明","dependent_library":"依存ライブラリ","source_code":"ソースコード","reference":"リファレンス","function":"関数","calc_amount":"計算量","constant_multiple":"定数倍","very_light":"とても軽い","light":"軽い","very_heavy":"とても重い","normal":"普通","little_heavy":"少し重い"}}'),delete e.options._Ctor}},296:function(e,t){e.exports=function(e){e.options.__i18n=e.options.__i18n||[],e.options.__i18n.push('{"en":{"explanation":"Explanation","dependent_library":"Dependent Library","source_code":"Source Code","reference":"Reference","function":"Function","calc_amount":"Calculated Amount","constant_multiple":"Constant Multiple","very_light":"Very Light","light":"Light","very_heavy":"Very Heavy","normal":"Normal","little_heavy":"Little Heavy"}}'),delete e.options._Ctor}},297:function(e,t,n){"use strict";var o=n(294);n.n(o).a},298:function(e,t,n){(t=n(13)(!1)).push([e.i,".source-copy .v-icon{position:absolute;right:0;z-index:4}.source-github .v-icon{position:absolute}",""]),e.exports=t},299:function(e,t,n){"use strict";n(184),n(120),n(303),n(304);var o=n(305),r=n.n(o);var c={props:["src","link"],components:{Prism:function(){return n.e(22).then(n.t.bind(null,375,7))}},data:function(){return{copied:!1,source_code:""}},methods:{copySource:function(){var element;(element=this.$el.querySelector("pre")).setAttribute("contenteditable","true"),element.focus(),document.execCommand("selectAll",!1),document.execCommand("copy"),element.setAttribute("contenteditable","false")},openSource:function(){open(this.link,"_blank")}},mounted:function(){var e=this;r.a.get(this.src).then((function(t){return e.source_code=t.data}))}},l=(n(297),n(67)),_=n(94),d=n.n(_),h=n(371),f=n(137),component=Object(l.a)(c,(function(){var e=this.$createElement,t=this._self._c||e;return t("v-card",{staticClass:"source-card",attrs:{outlined:"",color:"#2d2d2d"}},[t("div",{staticClass:"source-copy"},[t("v-icon",{attrs:{title:"Copy","aria-label":"Copy",size:"25",color:"white"},on:{click:this.copySource}},[this._v("\n      mdi-content-copy\n    ")])],1),this._v(" "),t("div",{staticClass:"source-github"},[t("v-icon",{attrs:{title:"View on GitHub","aria-label":"View on GitHub",color:"white",size:"25"},on:{click:this.openSource}},[this._v(" \n      mdi-github \n    ")])],1),this._v(" "),t("prism",{attrs:{language:"cpp",code:this.source_code}})],1)}),[],!1,null,null,null);t.a=component.exports;d()(component,{VCard:h.a,VIcon:f.a})},300:function(e,t,n){"use strict";var o=n(295),r=n.n(o);t.default=r.a},301:function(e,t,n){"use strict";var o=n(296),r=n.n(o);t.default=r.a},302:function(e,t,n){"use strict";var o={props:["sourceRaw","sourceGitHubLink","dependentList","japanese","english"],components:{SourceView:n(299).a},data:function(){return{dependent_libraries:"",reference_about:"",func_reference:""}},mounted:function(){this.$i18n.mergeLocaleMessage("ja",this.japanese),this.$i18n.mergeLocaleMessage("en",this.english),this.dependent_libraries=this.dependentList.dependent_libraries,this.reference_about=this.dependentList.reference_about,this.func_reference=this.dependentList.func_reference,window.MathJax&&(window.MathJax.Hub.Config({tex2jax:{inlineMath:[["$","$"]],displayMath:[["$$","$$"]],processEscapes:!0,processEnvironments:!0},displayAlign:"center","HTML-CSS":{fonts:["TeX"]}}),window.MathJax.Hub.Rerender(["Typeset",window.MathJax.Hub]))},head:function(){return{title:this.$t("library_name")}}},r=n(67),c=n(300),l=n(301),_=n(94),d=n.n(_),h=n(136),f=n(374),component=Object(r.a)(o,(function(){var e=this,t=e.$createElement,n=e._self._c||t;return n("v-responsive",{staticClass:"mx-auto",attrs:{"max-width":"1024"}},[n("section",{staticClass:"mb-12"},[n("h1",{staticClass:"display-1 font-weight-bold mb-2"},[e._v(" "+e._s(e.$t("library_name"))+" ")]),e._v(" "),n("p",{staticClass:"font-weight-right title"},[e._v(" \n      "+e._s(e.$t("overview"))+"\n    ")])]),e._v(" "),n("section",{staticClass:"mb-12"},[n("h2",[e._v(" "+e._s(e.$t("explanation"))+" ")]),e._v(" "),n("p",[e._v(" "+e._s(e.$t("explanation_content")))])]),e._v(" "),e.dependent_libraries?n("section",{staticClass:"mb-12"},[n("h2",[e._v(" "+e._s(e.$t("dependent_library"))+" ")]),e._v(" "),e._l(e.dependent_libraries,(function(t){return n("ul",[n("li",[n("nuxt-link",{attrs:{to:e.localePath(t.link)}},[e._v(" "+e._s(e.$t(t.name))+" ")])],1)])}))],2):e._e(),e._v(" "),e.func_reference?n("section",{staticClass:"mb-12"},[n("h2",[e._v(" "+e._s(e.$t("reference"))+" ")]),e._v(" "),e.reference_about?n("p",[e._v(" "+e._s(e.$t("reference_about"))+" ")]):e._e(),e._v(" "),n("v-simple-table",{scopedSlots:e._u([{key:"default",fn:function(){return[n("thead",[n("th",[e._v(" "+e._s(e.$t("function"))+" ")]),e._v(" "),n("th",{attrs:{width:"300sp"}},[e._v(" "+e._s(e.$t("explanation"))+" ")]),e._v(" "),n("th",[e._v(" "+e._s(e.$t("calc_amount"))+" ")]),e._v(" "),n("th",[e._v(" "+e._s(e.$t("constant_multiple"))+" ")])]),e._v(" "),n("tbody",e._l(e.func_reference,(function(t){return n("tr",{key:t.function},[n("td",[e._v(" "+e._s(t.function)+" ")]),e._v(" "),n("td",[e._v(" "+e._s(e.$t(t.explanation))+" ")]),e._v(" "),n("td",[e._v(" "+e._s(t.amount)+" ")]),e._v(" "),n("td",[e._v("  "+e._s(e.$t(t.constant_times))+" ")])])})),0)]},proxy:!0}],null,!1,207152778)})],1):e._e(),e._v(" "),n("section",{staticClass:"mb-12"},[n("h2",[e._v(" "+e._s(e.$t("source_code"))+" ")]),e._v(" "),n("SourceView",{attrs:{src:e.sourceRaw,link:e.sourceGitHubLink}})],1)])}),[],!1,null,null,null);"function"==typeof c.default&&Object(c.default)(component),"function"==typeof l.default&&Object(l.default)(component);t.a=component.exports;d()(component,{VResponsive:h.a,VSimpleTable:f.a})},345:function(e){e.exports=JSON.parse('{"ja":{"library_name":"BIT(Binary-Indexed-Tree)","overview":"BITはある区間の総和を$O(\\\\log{N})$で取得することが出来るデータ構造である．","explanation_content":"BITはFenwick木とも呼ばれ，数列に対して値を足す操作と，区間和を求める操作を$O(\\\\log{N})$，すなわち対数時間で行なうことが出来るデータ構造である．セグメント木に比べると実装が単純なので定数倍も軽い．","reference_about":"型Tは基本的にintかlong longかmodint","constructor_explanation":"コンストラクタ，データ保持数$size$で初期化","update_explanation":"$i$番目の値に$x$を足す","sum_explanation":"閉区間$[0, i]$の区間和を求める","sum_all_explanation":"数列の和を求める","query_explanation":"半開区間$[l, r)$の区間和を求める","2times":"とても軽い$(2倍)$"}}')},346:function(e){e.exports=JSON.parse('{"en":{"library_name":"BIT(Binary-Indexed-Tree)","overview":"BIT is a data structure in which the sum of a certain interval can be obtained by $O(\\\\log{N})$.","explanation_content":"BIT, also called Fenwick tree, is a data structure that can be used to add values to a sequence of numbers and to find the interval sum in $O(log{N})$, that is, in logarithmic time. Compared to segment trees, the implementation is simpler and the constant times are lighter.","reference_about":"The type T is basically an int, long long or modint","constructor_explanation":"Constructor, initialized with the number of data holdings $size$.","update_explanation":"Add $x$ to the $i$th value.","sum_explanation":"Find the interval sum of the closed interval $[0, i]$","sum_all_explanation":"Compute the sum of a sequence of numbers.","query_explanation":"Find the interval sum of the semi-open interval $[l, r)$","2times":"Very Light (two times)"}}')},377:function(e,t,n){"use strict";n.r(t);var o=n(302),r=function(){return{reference_about:"reference_about",func_reference:[{function:"BinaryIndexedTree$(size)$",explanation:"constructor_explanation",amount:"$O(N)$",constant_times:"very_light"},{function:"update$(i, x)$",explanation:"update_explanation",amount:"$O(\\log{N})$",constant_times:"very_light"},{function:"sum$(i)$",explanation:"sum_explanation",amount:"$O(\\log{N})$",constant_times:"very_light"},{function:"sum_all$()$",explanation:"sum_all_explanation",amount:"$O(\\log{N})$",constant_times:"very_light"},{function:"query$(l, r)$",explanation:"query_explanation",amount:"$O(\\log{N})$",constant_times:"2times"}]}},c=n(345),l=n(346),_={components:{LibraryPage:o.a},data:function(){return{Japanese:c,English:l,dependent_list:r()}}},d=n(67),component=Object(d.a)(_,(function(){var e=this.$createElement;return(this._self._c||e)("LibraryPage",{attrs:{sourceRaw:"https://raw.githubusercontent.com/jellyfish26/competitive-library/master/datastructure/BinaryIndexedTree.cpp",sourceGitHubLink:"https://github.com/jellyfish26/competitive-library/blob/master/datastructure/BinaryIndexedTree.cpp",dependentList:this.dependent_list,japanese:this.Japanese.ja,english:this.English.en}})}),[],!1,null,null,null);t.default=component.exports}}]);