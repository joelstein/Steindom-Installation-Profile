<div class="panel-display subtheme-home clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="subtheme-home-container subtheme-home-content-container clearfix">
    <div class="subtheme-home-sidebar subtheme-home-content-region panel-panel">
      <div class="subtheme-home-sidebar-inner subtheme-home-content-region-inner panel-panel-inner">
        <?php print $content['sidebar']; ?>
      </div>
    </div>
    <div class="subtheme-home-content subtheme-home-content-region panel-panel">
      <div class="subtheme-home-content-inner subtheme-home-content-region-inner panel-panel-inner">
        <?php print $content['content_main']; ?>
      </div>
    </div>
  </div>

</div>
