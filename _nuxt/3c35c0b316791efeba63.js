(window.webpackJsonp=window.webpackJsonp||[]).push([[5],{295:function(t,e,n){var content=n(299);"string"==typeof content&&(content=[[t.i,content,""]]),content.locals&&(t.exports=content.locals);(0,n(14).default)("4f4aef1d",content,!0,{sourceMap:!1})},296:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"ja":{"explanation":"説明","dependent_library":"依存ライブラリ","source_code":"ソースコード","reference":"リファレンス","function":"関数","calc_amount":"計算量","constant_multiple":"定数倍","very_light":"とても軽い"}}'),delete t.options._Ctor}},297:function(t,e){t.exports=function(t){t.options.__i18n=t.options.__i18n||[],t.options.__i18n.push('{"en":{"explanation":"Explanation","dependent_library":"Dependent Library","source_code":"Source Code","reference":"Reference","function":"Function","calc_amount":"Calculated Amount","constant_multiple":"Constant Multiple","very_light":"Very Light"}}'),delete t.options._Ctor}},298:function(t,e,n){"use strict";var o=n(295);n.n(o).a},299:function(t,e,n){(e=n(13)(!1)).push([t.i,".source-copy .v-icon{position:absolute;right:0;z-index:4}.source-github .v-icon{position:absolute}",""]),t.exports=e},300:function(t,e,n){"use strict";n(185),n(120),n(301),n(302);var o=n(303),r=n.n(o);var c={props:["src","link"],components:{Prism:function(){return n.e(10).then(n.t.bind(null,351,7))}},data:function(){return{copied:!1,source_code:""}},methods:{copySource:function(){var element;(element=this.$el.querySelector("pre")).setAttribute("contenteditable","true"),element.focus(),document.execCommand("selectAll",!1),document.execCommand("copy"),element.setAttribute("contenteditable","false")},openSource:function(){open(this.link,"_blank")}},mounted:function(){var t=this;r.a.get(this.src).then((function(e){return t.source_code=e.data}))}},l=(n(298),n(67)),h=n(94),_=n.n(h),d=n(347),f=n(137),component=Object(l.a)(c,(function(){var t=this.$createElement,e=this._self._c||t;return e("v-card",{staticClass:"source-card",attrs:{outlined:"",color:"#2d2d2d"}},[e("div",{staticClass:"source-copy"},[e("v-icon",{attrs:{title:"Copy","aria-label":"Copy",size:"25",color:"white"},on:{click:this.copySource}},[this._v("\n      mdi-content-copy\n    ")])],1),this._v(" "),e("div",{staticClass:"source-github"},[e("v-icon",{attrs:{title:"View on GitHub","aria-label":"View on GitHub",color:"white",size:"25"},on:{click:this.openSource}},[this._v(" \n      mdi-github \n    ")])],1),this._v(" "),e("prism",{attrs:{language:"cpp",code:this.source_code}})],1)}),[],!1,null,null,null);e.a=component.exports;_()(component,{VCard:d.a,VIcon:f.a})},310:function(t,e,n){"use strict";var o=n(296),r=n.n(o);e.default=r.a},311:function(t,e,n){"use strict";var o=n(297),r=n.n(o);e.default=r.a},312:function(t,e,n){"use strict";var o=n(300),r={props:["formula"],watch:{formula:function(){this.renderMathJax()}},mounted:function(){this.renderMathJax()},methods:{renderMathJax:function(){this.$refs.mathJaxElement.innerHTML=this.formula,window.MathJax&&(window.MathJax.Hub.Config({tex2jax:{inlineMath:[["$","$"]],displayMath:[["$$","$$"]],processEscapes:!0,processEnvironments:!0},displayAlign:"center","HTML-CSS":{fonts:["TeX"]}}),window.MathJax.Hub.Queue(["Typeset",window.MathJax.Hub,this.$refs.mathJaxElement]))}}},c=n(67),l=Object(c.a)(r,(function(){var t=this.$createElement;return(this._self._c||t)("span",{ref:"mathJaxElement"},[this._v(this._s(this.formula))])}),[],!1,null,null,null).exports,h={props:["sourceRaw","sourceGitHubLink","dependentList","japanese","english"],components:{SourceView:o.a,MathJax2:l},data:function(){return{dependent_libraries:"",reference_about:"",func_reference:""}},mounted:function(){this.$i18n.mergeLocaleMessage("ja",this.japanese),this.$i18n.mergeLocaleMessage("en",this.english),this.dependent_libraries=this.dependentList.dependent_libraries,this.reference_about=this.dependentList.reference_about,this.func_reference=this.dependentList.func_reference},head:function(){return{title:this.$t("library_name")}}},_=n(310),d=n(311),f=n(94),m=n.n(f),$=n(136),v=n(350),x=Object(c.a)(h,(function(){var t=this,e=t.$createElement,n=t._self._c||e;return n("v-responsive",{staticClass:"mx-auto",attrs:{"max-width":"1024"}},[n("section",{staticClass:"mb-12"},[n("h1",{staticClass:"display-1 font-weight-bold mb-2"},[t._v(" "+t._s(t.$t("library_name"))+" ")]),t._v(" "),n("p",{staticClass:"font-weight-right title"},[n("MathJax2",{attrs:{formula:t.$t("overview")}})],1)]),t._v(" "),n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("explanation"))+" ")]),t._v(" "),n("p",[n("MathJax2",{attrs:{formula:t.$t("explanation_content")}})],1)]),t._v(" "),t.dependent_libraries?n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("dependent_library"))+" ")]),t._v(" "),t._l(t.dependent_libraries,(function(e){return n("ul",[n("li",[n("a",{attrs:{href:t.localePath(e.link)}},[t._v(" "+t._s(t.$t(e.name))+" ")])])])}))],2):t._e(),t._v(" "),t.func_reference?n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("reference"))+" ")]),t._v(" "),t.reference_about?n("p",[n("MathJax2",{attrs:{formula:t.$t(t.reference_about)}})],1):t._e(),t._v(" "),n("v-simple-table",{scopedSlots:t._u([{key:"default",fn:function(){return[n("thead",[n("th",{attrs:{width:"250sp"}},[t._v(" "+t._s(t.$t("function"))+" ")]),t._v(" "),n("th",{attrs:{width:"300sp"}},[t._v(" "+t._s(t.$t("explanation"))+" ")]),t._v(" "),n("th",[t._v(" "+t._s(t.$t("calc_amount"))+" ")]),t._v(" "),n("th",[t._v(" "+t._s(t.$t("constant_multiple"))+" ")])]),t._v(" "),n("tbody",t._l(t.func_reference,(function(e){return n("tr",{key:e.function},[n("td",[n("MathJax2",{attrs:{formula:e.function}})],1),t._v(" "),n("td",[n("MathJax2",{attrs:{formula:t.$t(e.explanation)}})],1),t._v(" "),n("td",[n("MathJax2",{attrs:{formula:e.amount}})],1),t._v(" "),n("td",[n("MathJax2",{attrs:{formula:t.$t(e.constant_times)}})],1)])})),0)]},proxy:!0}],null,!1,3476379124)})],1):t._e(),t._v(" "),n("section",{staticClass:"mb-12"},[n("h2",[t._v(" "+t._s(t.$t("source_code"))+" ")]),t._v(" "),n("SourceView",{attrs:{src:t.sourceRaw,link:t.sourceGitHubLink}})],1)])}),[],!1,null,null,null);"function"==typeof _.default&&Object(_.default)(x),"function"==typeof d.default&&Object(d.default)(x);e.a=x.exports;m()(x,{VResponsive:$.a,VSimpleTable:v.a})},345:function(t){t.exports=JSON.parse('{"ja":{"library_name":"素集合データ構造(Union-Find)","overview":"UnionFindとは，グループ分け(集合)を木構造で管理し，高速に判定等を行なうデータ構造である．","explanation_content":"UnionFindは，集合を木構造で管理し，グループの併合や同じグループに属しているかの判定を$O(a(N))$($a$はアッカーマンの逆関数)で行なうことが出来るデータ構造である．","constructor_explanation":"コンストラクタ，データ保持数$size$で初期化","same_explanation":"$x$と$y$が同じ集合に属しているか判定する．","2times":"とても軽い(2倍)","unite_explanation":"$x$が属する集合と$y$が属する集合を併合する．すでに併合されているなら$false$が返り値となる．","unite_constant_times":"とても軽い(same関数)","find_explanation":"$i$が属する集合の木構造の根を返し，更にデータの更新を行なう．","size_explanation":"$i$が属する集合の大きさを求める．"}}')},346:function(t){t.exports=JSON.parse('{"en":{"library_name":"Disjoint-set(Union-Find)","overview":"UnionFind is a data structure that manages a set as a tree structure and performs fast judgment.","explanation_content":"UnionFind is a data structure that manages a set as a tree structure and allows us to merge groups and determine whether they belong to the same group by $O(a(N))$($a$ is an inverse function of Ackermann\'s).","constructor_explanation":"Constructor, initialized with the number of data holdings $size$.","same_explanation":"Determines whether $x$ and $y$ belong to the same set.","2times":"Very Light(2times)","unite_explanation":"Merge the set to which $x$ belongs and the set to which $y$ belongs. If it has already been merged, $false$ is the return value.","unite_constant_times":"Very Light(same function)","find_explanation":"Returns the root of the tree structure of the set to which $i$ belongs, and further updates the data.","size_explanation":"Calculates the size of the set to which $i$ belongs."}}')},353:function(t,e,n){"use strict";n.r(e);var o=n(312),r=function(){return{func_reference:[{function:"UnionFind$(size)$",explanation:"constructor_explanation",amount:"$O(N)$",constant_times:"very_light"},{function:"same$(x, y)$",explanation:"same_explanation",amount:"$O(a(N))$",constant_times:"2times"},{function:"unite$(x, y)$",explanation:"unite_explanation",amount:"$O(1)$",constant_times:"unite_constant_times"},{function:"find$(i)$",explanation:"find_explanation",amount:"$O(a(N))$",constant_times:"very_light"},{function:"size$(i)$",explanation:"size_explanation",amount:"$O(1)$",constant_times:"very_light"}]}},c=n(345),l=n(346),h={components:{LibraryPage:o.a},data:function(){return{Japanese:c,English:l,dependent_list:r()}}},_=n(67),component=Object(_.a)(h,(function(){var t=this.$createElement;return(this._self._c||t)("LibraryPage",{attrs:{sourceRaw:"https://raw.githubusercontent.com/jellyfish26/competitive-library/master/datastructure/UnionFind.cpp",sourceGitHubLink:"https://github.com/jellyfish26/competitive-library/blob/master/datastructure/UnionFind.cpp",dependentList:this.dependent_list,japanese:this.Japanese.ja,english:this.English.en}})}),[],!1,null,null,null);e.default=component.exports}}]);