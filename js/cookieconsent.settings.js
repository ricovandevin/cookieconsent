window.cookieconsent_options = {
  // The message shown by the plugin.
  message: Drupal.settings.cookieconsent.message,
  // The text used on the dismiss button.
  dismiss: Drupal.settings.cookieconsent.dismiss,
  // The text shown on the link to the cookie policy (requires the link option to also be set)
  learnMore: Drupal.settings.cookieconsent.learnMore,
  // The url of your cookie policy. If it’s set to null, the link is hidden.
  link: Drupal.settings.cookieconsent.link,
  // The element you want the Cookie Consent notification to be appended to. If null, the Cookie Consent plugin
  // is appended to the body.
  container: Drupal.settings.cookieconsent.container,
  // The theme you wish to use. Can be any of the themes from the style directory, e.g. dark-top.
  // If you wish to use your own CSS instead, specify the URL of your CSS file. e.g. styles/my_custom_theme.css.
  // This can be a relative or absolute URL.
  // To stop Cookie Consent from loading CSS at all, specify false
  theme: Drupal.settings.cookieconsent.theme,
  // The path for the consent cookie that Cookie Consent uses, to remember that users have consented to cookies.
  // Use to limit consent to a specific path within your website.
  path: Drupal.settings.cookieconsent.path,
  // The domain for the consent cookie that Cookie Consent uses, to remember that users have consented to cookies.
  // Useful if your website uses multiple subdomains, e.g. if your script is hosted at www.example.com you might
  // override this to example.com, thereby allowing the same consent cookie to be read by subdomains
  // like foo.example.com.
  domain: Drupal.settings.cookieconsent.domain,
  // The number of days Cookie Consent should store the user’s consent information for.
  expiryDays: Drupal.settings.cookieconsent.expiry,
  // The target of the link to your cookie policy. Use to open a link in a new window, or specific frame, if you wish.
  target: Drupal.settings.cookieconsent.target,
  markup: [
    '<div class="cc_banner-wrapper {{containerClasses}}">',
    Drupal.settings.cookieconsent.markup,
    '</div>'
  ]
};