(function ($) {
  Drupal.behaviors.content_type_extras_cancel_button = {
    attach: function(context, settings) {
      $('form.node-form #edit-cancel, form.node-form #edit-cancel--2').click(function() {
        var answer = confirm(Drupal.t('Are you sure you want to cancel and lose all changes?'));
        if (answer) {
          history.go(-1);
        }
      });
    }
  }
})(jQuery);